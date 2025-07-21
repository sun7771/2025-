#include "gt911.h"
#include "string.h" // 用于 strcmp
#include "stdio.h"  // 用于 printf

// 定义全局触摸设备和 LCD 设备变量（在 main.c 中实例化并初始化）
tp_dev_t tp_dev;
lcd_dev_t lcddev = { .dir = 1, .width = 320, .height = 240 };

// 您的 I2C 句柄的外部声明。请务必在 main.c 或您的 I2C 初始化文件中定义并初始化它。

// 将数据写入 GT911 寄存器的函数
// reg: 起始寄存器地址 (16 位)
// buf: 要写入的数据缓冲区
// len: 要写入的数据长度
// 返回值: 0 表示成功，1 表示失败。
u8 GT911_WR_Reg(u16 reg, u8 *buf, u8 len) {
	// HAL_I2C_Mem_Write 函数期望的设备地址是 7 位地址左移 1 位，以包含 R/W 位。
	// 但是，HAL 库内部会处理这个移位。
	// 所以，这里传入的 (GT_CMD_WR << 1) 是 8 位地址（包含 R/W 位）。
	// GT911 的 7 位地址是 0x5D。对于 HAL，我们直接传递 0x5D。
	// HAL 内部会将 7 位地址左移 1 位，并在最低位添加 R/W 位。
	// 因此，这里应该是 (GT_CMD_WR << 1)
	// 0x5D << 1 = 0xBA (写地址)
	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&hi2c2, (GT_CMD_WR << 1), reg,
			I2C_MEMADD_SIZE_16BIT, buf, len, HAL_MAX_DELAY);
	return (status == HAL_OK) ? 0 : 1;
}

// 从 GT911 寄存器读取数据的函数
// reg: 起始寄存器地址 (16 位)
// buf: 存储读取数据的缓冲区
// len: 要读取的数据长度
void GT911_RD_Reg(u16 reg, u8 *buf, u8 len) {
	// 0x5D << 1 | 0x01 = 0xBB (读地址)
	HAL_I2C_Mem_Read(&hi2c2, (GT_CMD_RD << 1), reg, I2C_MEMADD_SIZE_16BIT, buf,
			len, HAL_MAX_DELAY);
}

// 初始化 GT911 触摸屏
// 返回值: 0 表示初始化成功，1 表示初始化失败
u8 GT911_Init(void) {
	u8 temp[5];

	// 初始化 RST 和 INT 引脚
	// 这些 GPIO 必须在 STM32CubeMX 中配置为相应的模式
	// GT_RST_Pin: GPIO_Output, Push-Pull, High Level, No Pull
	// GT_INT_Pin: 初始为 GPIO_Output, Push-Pull, Low Level, No Pull (用于地址选择)
	//             然后会在代码中切换为 GPIO_Input, Pull-Down

	/****************************时序开始**************************/
	// 以下时序用于设置 I2C 地址，不可更改。
	// 确保 GT_RST 和 GT_INT 引脚在 MX_GPIO_Init() 中已经配置为输出推挽模式。
	HAL_GPIO_WritePin(GT_RST_GPIO_Port, GT_RST_Pin, GPIO_PIN_RESET); // 1. RESET rst & int
	HAL_GPIO_WritePin(GT_INT_GPIO_Port, GT_INT_Pin, GPIO_PIN_RESET);
	HAL_Delay(5); // 延迟 5ms

	// 将 INT 设置为输出高电平，用于选择 I2C 地址 (0x5D)
	HAL_GPIO_WritePin(GT_INT_GPIO_Port, GT_INT_Pin, GPIO_PIN_SET);
	HAL_Delay(5); // 延迟 5ms (大于 100us)

	// 释放 RST，GT911 开始启动
	HAL_GPIO_WritePin(GT_RST_GPIO_Port, GT_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(10); // 延迟 10ms (大于 5ms)

	// INT 切换到下拉输入状态，用于中断检测
	// 重新配置 INT 引脚为输入下拉
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = GT_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN; // 下拉电阻
	HAL_GPIO_Init(GT_INT_GPIO_Port, &GPIO_InitStruct);

	/****************************时序结束**************************/

	HAL_Delay(100); // 等待芯片稳定

	GT911_RD_Reg(GT_PID_REG, temp, 4); // 读取产品 ID
	temp[4] = 0;                       // 为 printf 添加空终止符
	printf("CTP ID:%s\r\n", temp);     // 打印 ID

	if (strcmp((char*) temp, "911") == 0) // 如果 ID 是 "911"
			{
		temp[0] = 0X02;                     // 软复位命令 (写入 0x02 到 GT_CTRL_REG)
		GT911_WR_Reg(GT_CTRL_REG, temp, 1); // 软复位 GT911
		HAL_Delay(10);
		temp[0] = 0X00;                     // 结束复位命令 (写入 0x00 到 GT_CTRL_REG)
		GT911_WR_Reg(GT_CTRL_REG, temp, 1); // 结束复位
		return 0;                           // 成功
	}
	return 1; // 失败
}

// 触摸点寄存器地址表
const u16 GT911_TPX_TBL[5] = { GT_TP1_REG, GT_TP2_REG, GT_TP3_REG, GT_TP4_REG,
		GT_TP5_REG };

/**
 * @brief  获取 GT911 触摸屏的触摸点坐标。
 * @param  touch_data: 指向 tp_dev_t 结构体的指针，用于存储读取到的触摸数据。
 * 函数会更新其 x, y, 和 sta 成员。
 * @retval 实际检测到的有效触摸点数量 (0-5)。
 */
u8 GT911_GetTouchCoordinates(tp_dev_t *touch_data) {
	u8 buf[4];
	u8 i;
	u8 touch_points_count = 0;
	u8 temp_status;

	// 清空上次的触摸数据，确保每次获取都是最新状态
	for (i = 0; i < 5; i++) {
		touch_data->x[i] = 0xFFFF; // 使用 0xFFFF 表示无效坐标
		touch_data->y[i] = 0xFFFF;
	}
	touch_data->sta = 0; // 清空状态位

	GT911_RD_Reg(GT_GSTID_REG, &temp_status, 1); // 读取触摸点状态寄存器 (0x814E)

	// 检查是否有触摸点 (0x814E 的低 4 位表示触摸点数)
	// 并且触摸点数有效 (1-5)
	touch_points_count = temp_status & 0XF;
	if (touch_points_count > 0 && touch_points_count < 6) {
		// 根据触摸点数量设置有效位
		touch_data->sta = (~(0XFF << touch_points_count)) | TP_PRES_DOWN
				| TP_CATH_PRES;

		for (i = 0; i < touch_points_count; i++) {
			GT911_RD_Reg(GT911_TPX_TBL[i], buf, 4); // 读取触摸点的 XY 坐标值
													// buf[0]: X低8位, buf[1]: X高8位
													// buf[2]: Y低8位, buf[3]: Y高8位

			// 根据 LCD 方向进行坐标转换
			if (lcddev.dir == 0) // 竖屏模式 (X方向保持不变，Y方向保持不变)
					{
				touch_data->x[i] = ((u16) buf[1] << 8) + buf[0];
				touch_data->y[i] = ((u16) buf[3] << 8) + buf[2];
			} else // 横屏模式 (触摸屏的X变成LCD的Y，触摸屏的Y变成LCD的X)
			{
				// GT911 默认输出的 X 是宽度方向，Y 是高度方向。
				// 对于横屏，通常触摸屏的宽度方向（GT911的X）对应LCD的高度方向（Y），
				// 而触摸屏的高度方向（GT911的Y）对应LCD的宽度方向（X）。
				// 且 Y 坐标可能需要反向（根据具体屏幕安装方向）
				// 横屏，GT911的Y作为LCD的X，GT911的X作为LCD的Y
				touch_data->x[i] = ((u16) buf[3] << 8) + buf[2];
				touch_data->y[i] = lcddev.height - 1
						- (((u16) buf[1] << 8) + buf[0]);
			}
			printf("x[%d]:%d,y[%d]:%d\r\n", i, touch_data->x[i], i,
					touch_data->y[i]); // 串口打印坐标，用于调试
		}

		// 如果读取到的第一个触摸点数据都是 0，则忽略此次数据（可能是无效数据）
		if (touch_data->x[0] == 0 && touch_data->y[0] == 0) {
			touch_points_count = 0;
			touch_data->sta = 0; // 强制将状态设置为无触摸
		}
	} else // 没有触摸点
	{
		touch_points_count = 0;
		touch_data->sta = 0;
	}

	// 检查是否有需要清除的触摸标志位 (0x814E 的 D7 位为 1 表示有数据待处理)
	if (temp_status & 0X80) {
		temp_status = 0; // 将 0x814E 寄存器的 D7 位清零
		GT911_WR_Reg(GT_GSTID_REG, &temp_status, 1); // 写入 0x00 清除标志
	}

	return touch_points_count;
}

// 扫描触摸屏（轮询方式）
// mode: 0, 正常扫描. (此参数在当前实现中未使用，保留用于兼容性)
// 返回值: 触摸屏状态.
// 0, 触摸屏无触摸; 1, 触摸屏有触摸
//u8 GT911_Scan(u8 mode)
//{
//    static u8 t = 0; // 控制查询间隔，从而降低 CPU 占用率
//    u8 touch_points_detected = 0;
//
//    t++;
//    // 空闲时每进入 10 次 GT911_Scan 函数才检测 1 次，从而节省 CPU 使用率
//    // 如果最近有触摸，则频繁检测
//    if ((t % 10) == 0 || (tp_dev.sta & TP_PRES_DOWN) || t < 10)
//    {
//        touch_points_detected = GT911_GetTouchCoordinates(&tp_dev); // 调用新的函数获取触摸数据
//
//        if (touch_points_detected > 0)
//        {
//            t = 0; // 触发一次触摸后，将计数器清零，强制连续监测一段时间以提高命中率
//            return 1; // 检测到触摸
//        }
//    }
//
//    // 如果没有触摸点按下，且之前是按下状态，则标记松开
//    if (!(tp_dev.sta & TP_PRES_DOWN) && (tp_dev.sta & TP_CATH_PRES)) // 如果没有按下标志但有有效点标志，说明刚松开
//    {
//        tp_dev.sta &= ~(TP_PRES_DOWN | TP_CATH_PRES); // 清除按下和有效点标志
//        tp_dev.x[0] = 0xFFFF; // 将第一个点坐标设置为无效值
//        tp_dev.y[0] = 0xFFFF;
//    }
//    // 如果完全没有触摸，确保状态清零
//    else if (touch_points_detected == 0)
//    {
//         tp_dev.sta = 0; // 清除所有状态
//         tp_dev.x[0] = 0xFFFF; // 将第一个点坐标设置为无效值
//         tp_dev.y[0] = 0xFFFF;
//    }
//
//    if (t > 240) // 防止计数器溢出，或者保持周期性检查
//        t = 10;  // 重新从 10 开始计数，确保即使长期无触摸也能周期性检查
//
//    return (tp_dev.sta & TP_PRES_DOWN) ? 1 : 0; // 返回当前是否有触摸按下
//}

u8 GT911_Scan(u8 mode) {
	u8 touch_points_detected = 0;

	// 直接每次都采集
	touch_points_detected = GT911_GetTouchCoordinates(&tp_dev);

	if (touch_points_detected > 0) {
		return 1;
	}

	// 如果没有触摸点按下，且之前是按下状态，则标记松开
	if (!(tp_dev.sta & TP_PRES_DOWN) && (tp_dev.sta & TP_CATH_PRES)) {
		tp_dev.sta &= ~(TP_PRES_DOWN | TP_CATH_PRES);
		tp_dev.x[0] = 0xFFFF;
		tp_dev.y[0] = 0xFFFF;
	} else if (touch_points_detected == 0) {
		tp_dev.sta = 0;
		tp_dev.x[0] = 0xFFFF;
		tp_dev.y[0] = 0xFFFF;
	}

	return (tp_dev.sta & TP_PRES_DOWN) ? 1 : 0;
}

// 空扫描函数，当没有触摸时可以调用此函数
u8 Null_Scan(u8 i) {
	return 0;
}
