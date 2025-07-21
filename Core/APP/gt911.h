#ifndef __SYS_H
#define __SYS_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#include "mybsp.h"
#define TP_PRES_DOWN 0x80 // 触摸按下标志
#define TP_CATH_PRES 0x40 // 触摸点有效（存在候选点）标志

// 触摸设备结构体
typedef struct {
	u16 x[5]; // x坐标数组，最多支持5个触摸点
	u16 y[5]; // y坐标数组，最多支持5个触摸点
	u8 sta;   // 触摸状态
			  // sta&0x80：按下（1），松开（0）
			  // sta&0x3F：有效触摸点的数量 (0~5)
			  // 例如：如果sta=0x81，表示有一个点按下
} tp_dev_t;

extern tp_dev_t tp_dev; // 声明全局触摸设备变量
// LCD 设备结构体
typedef struct {
	u16 width;  // LCD 宽度
	u16 height; // LCD 高度
	u8 dir;     // LCD 显示方向 (0: 竖屏, 1: 横屏)
// 您可以根据需要添加其他 LCD 参数，例如颜色深度等
} lcd_dev_t;

extern lcd_dev_t lcddev; // 声明全局 LCD 设备变量

extern I2C_HandleTypeDef hi2c2; // 声明您的 I2C 句柄

// GT911 复位和中断引脚定义
// 这些宏需要与您在 STM32CubeMX 中配置的 GPIO 引脚匹配
// 示例：如果 GT_RST 连接到 GPIOC 的 GPIO_PIN_14，GT_INT 连接到 GPIOC 的 GPIO_PIN_15
#define GT_RST_GPIO_Port GPIOB
#define GT_RST_Pin       GPIO_PIN_12

#define GT_INT_GPIO_Port GPIOC
#define GT_INT_Pin       GPIO_PIN_13

// GT911 I2C 设备地址
// GT911 支持两种 I2C 地址: 0x14 (0x28/0x29) 和 0x5D (0xBA/0xBB)
// 此驱动使用 0x14 (7位地址)，其8位写地址为 0x28，8位读地址为 0x29。
// HAL 库通常需要 7 位地址，并在内部进行左移。
#define GT_CMD_WR 0X5D // GT911 的 7 位 I2C 设备地址 (写)
#define GT_CMD_RD 0X5D // GT911 的 7 位 I2C 设备地址 (读)

// GT911 部分寄存器定义
#define GT_CTRL_REG  0X8040 // GT911 控制寄存器
#define GT_CFGS_REG  0X8047 // GT911 配置起始地址寄存器
#define GT_CHECK_REG 0X80FF // GT911 校验和寄存器
#define GT_PID_REG   0X8140 // GT911 产品 ID 寄存器

#define GT_GSTID_REG 0X814E // GT911 当前检测到的触摸情况寄存器
#define GT_TP1_REG   0X8150 // 第一个触摸点数据地址
#define GT_TP2_REG   0X8158 // 第二个触摸点数据地址
#define GT_TP3_REG   0X8160 // 第三个触摸点数据地址
#define GT_TP4_REG   0X8168 // 第四个触摸点数据地址
#define GT_TP5_REG   0X8170 // 第五个触摸点数据地址

// 函数原型
u8 GT911_WR_Reg(u16 reg, u8 *buf, u8 len);
void GT911_RD_Reg(u16 reg, u8 *buf, u8 len);
u8 GT911_Init(void);
u8 GT911_Scan(u8 mode);
u8 GT911_GetTouchCoordinates(tp_dev_t *touch_data); // 新增函数原型
u8 Null_Scan(u8 i); // 占位函数，用于无触摸时的扫描

#endif // __SYS_H
