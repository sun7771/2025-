#include "dht11.h"

// 定义 DHT11 数据引脚
#define DHT11_PORT GPIOB
#define DHT11_PIN GPIO_PIN_15

// 定义 GPIO 输入模式
static void DHT11_SetPinInput(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = DHT11_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

// 定义 GPIO 输出模式
static void DHT11_SetPinOutput(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = DHT11_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStruct);
}

// 延时函数（微秒级）
static void DHT11_DelayUs(uint16_t us) {
	__HAL_TIM_SET_COUNTER(&htim6, 0); // 使用定时器6
	while (__HAL_TIM_GET_COUNTER(&htim6) < us)
		;
}

// 初始化 DHT11
void DHT11_Init(void) {
	DHT11_SetPinOutput();
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET); // 拉高数据线
}

// 从 DHT11 读取数据
uint8_t DHT11_ReadData(float *temperature, float *humidity) {
	uint8_t data[5] = { 0 };
	uint8_t i, j;

	// 主机发送开始信号
	DHT11_SetPinOutput();
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_RESET);
	HAL_Delay(18); // 拉低至少18ms
	HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, GPIO_PIN_SET);
	DHT11_DelayUs(30); // 拉高20-40us

	// 切换为输入模式，等待 DHT11 响应
	DHT11_SetPinInput();

	// 检测 DHT11 响应信号
	if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_SET)
		return 1; // 未响应
	while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_RESET)
		; // 等待拉高
	while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_SET)
		;   // 等待拉低

	// 读取 40 位数据
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 8; i++) {
			while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_RESET)
				; // 等待拉高
			DHT11_DelayUs(40); // 延时 40us
			if (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_SET) {
				data[j] |= (1 << (7 - i)); // 读取到高电平
			}
			while (HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN) == GPIO_PIN_SET)
				; // 等待拉低
		}
	}

	// 校验和验证
	if (data[4] != (data[0] + data[1] + data[2] + data[3]))
		return 2;

	// 计算温湿度值（支持小数）
	*humidity = data[0] + (data[1] / 10.0);      // 湿度 = 整数部分 + 小数部分
	*temperature = data[2] + (data[3] / 10.0);   // 温度 = 整数部分 + 小数部分

	return 0; // 成功
}
