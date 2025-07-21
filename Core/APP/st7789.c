#include "st7789.h"
#include <string.h> // For memcpy if needed

// 引用你的SPI句柄 (由 CubeIDE 在 main.c 或 drivers.c 中生成)
// extern SPI_HandleTypeDef hspi1; // 在 st7789.h 中已 extern 声明

// --- 延迟函数 (使用HAL_Delay) ---
static void ST7789_Delay(uint32_t delay_ms) {
	HAL_Delay(delay_ms);
}

// --- SPI 发送数据/命令的基础函数 ---
static void ST7789_WriteByte(uint8_t data) {
	if (HAL_SPI_Transmit(&hspi1, &data, 1, HAL_MAX_DELAY) != HAL_OK) {
		Error_Handler(); // 处理传输错误
	}
}

void ST7789_WriteCommand(uint8_t cmd) {
	HAL_GPIO_WritePin(ST7789_DC_PORT, ST7789_DC_PIN, GPIO_PIN_RESET); // DC = 0 (命令)
	HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_RESET); // CS = 0 (使能)
	ST7789_WriteByte(cmd);
	HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_SET); // CS = 1 (禁用)
}

void ST7789_WriteData(uint8_t *buff, size_t buff_size) {
	HAL_GPIO_WritePin(ST7789_DC_PORT, ST7789_DC_PIN, GPIO_PIN_SET); // DC = 1 (数据)
	HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_RESET); // CS = 0 (使能)
	if (HAL_SPI_Transmit(&hspi1, buff, buff_size, HAL_MAX_DELAY) != HAL_OK) {
		Error_Handler(); // 处理传输错误
	}
	HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_SET); // CS = 1 (禁用)
}

// --- ST7789 屏幕初始化序列 ---
void ST7789_Init(void) {
	// 硬件复位
	HAL_GPIO_WritePin(ST7789_RST_PORT, ST7789_RST_PIN, GPIO_PIN_RESET); // RST = 0
	ST7789_Delay(100);
	HAL_GPIO_WritePin(ST7789_RST_PORT, ST7789_RST_PIN, GPIO_PIN_SET); // RST = 1
	ST7789_Delay(100);

	// 软件复位
	ST7789_WriteCommand(0x01); // Software reset
	ST7789_Delay(150);

	// 一系列初始化命令 (这是ST7789的标准初始化序列，可能需要根据你的屏幕模块微调)
	ST7789_WriteCommand(0x11); // Sleep out
	ST7789_Delay(255);

	ST7789_WriteCommand(0x3A); // Interface Pixel Format (像素格式)
	ST7789_WriteData((uint8_t[] ) { 0x05 }, 1); // 0x05 for 16-bit color (RGB565)

	ST7789_WriteCommand(0x36); // Memory Access Control (内存访问控制)
	// 240x320 竖屏：0x00 （默认）
	// 0x00: MY=0, MX=0, MV=0, ML=0, BGR=0 (正常竖屏)
	// 0xC0: MY=1, MX=1, MV=0, ML=0, BGR=0 (竖屏倒置)
	// 0x60: MY=0, MX=1, MV=1, ML=0, BGR=0 (横屏)
	// 0xA0: MY=1, MX=0, MV=1, ML=0, BGR=0 (横屏倒置)
	ST7789_WriteData((uint8_t[] ) { 0x60 }, 1); // 设置为正常竖屏

	ST7789_WriteCommand(0xB2); // Porch Setting
	ST7789_WriteData((uint8_t[] ) { 0x12, 0x12, 0x00, 0x33, 0x33 }, 5);

	ST7789_WriteCommand(0xB7); // Gate Control
	ST7789_WriteData((uint8_t[] ) { 0x35 }, 1);

	ST7789_WriteCommand(0xBB); // VCOM Setting
	ST7789_WriteData((uint8_t[] ) { 0x1A }, 1);

	ST7789_WriteCommand(0xC0); // LCM Control
	ST7789_WriteData((uint8_t[] ) { 0x2C }, 1);

	ST7789_WriteCommand(0xC2); // VDV and VRH Command Enable
	ST7789_WriteData((uint8_t[] ) { 0x01 }, 1);

	ST7789_WriteCommand(0xC3); // VRH Set
	ST7789_WriteData((uint8_t[] ) { 0x19 }, 1);

	ST7789_WriteCommand(0xC4); // VDV Set
	ST7789_WriteData((uint8_t[] ) { 0x20 }, 1);

	ST7789_WriteCommand(0xC6); // Frame Rate Control
	ST7789_WriteData((uint8_t[] ) { 0x0F }, 1);

	ST7789_WriteCommand(0xD0); // Power Control 1
	ST7789_WriteData((uint8_t[] ) { 0xA4, 0xA1 }, 2);

	ST7789_WriteCommand(0xE0); // Positive Voltage Gamma Control
	ST7789_WriteData((uint8_t[] ) { 0xD0, 0x00, 0x02, 0x07, 0x0A, 0x28, 0x32,
					0x44, 0x42, 0x06, 0x0E, 0x12, 0x14, 0x27, 0x09 }, 15);

	ST7789_WriteCommand(0xE1); // Negative Voltage Gamma Control
	ST7789_WriteData((uint8_t[] ) { 0xD0, 0x00, 0x02, 0x07, 0x0A, 0x28, 0x32,
					0x44, 0x42, 0x06, 0x0E, 0x12, 0x14, 0x27, 0x09 }, 15);

	ST7789_WriteCommand(0x2A); // Column Address Set (列地址设置)
	ST7789_WriteData(
			(uint8_t[] ) { 0x00, 0x00, (ST7789_WIDTH - 1) >> 8,
							(ST7789_WIDTH - 1) & 0xFF }, 4);

	ST7789_WriteCommand(0x2B); // Row Address Set (行地址设置)
	ST7789_WriteData(
			(uint8_t[] ) { 0x00, 0x00, (ST7789_HEIGHT - 1) >> 8,
							(ST7789_HEIGHT - 1) & 0xFF }, 4);

	ST7789_WriteCommand(0x21); // Display Inversion On (颜色反转)
	ST7789_WriteCommand(0x29); // Display ON (开启显示)
	ST7789_Delay(100);

	ST7789_SetBacklight(1); // 默认开启背光
}

// --- 设置显示区域 ---
void ST7789_SetAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
	// Column Address Set (CASET)
	ST7789_WriteCommand(0x2A);
	ST7789_WriteData(
			(uint8_t[] ) { (x1 >> 8) & 0xFF, x1 & 0xFF, (x2 >> 8) & 0xFF,
							x2 & 0xFF }, 4);

	// Row Address Set (RASET)
	ST7789_WriteCommand(0x2B);
	ST7789_WriteData(
			(uint8_t[] ) { (y1 >> 8) & 0xFF, y1 & 0xFF, (y2 >> 8) & 0xFF,
							y2 & 0xFF }, 4);

	// Memory Write (RAMWR)
	ST7789_WriteCommand(0x2C);
}

// --- 画点函数 ---
void ST7789_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
	if ((x >= ST7789_WIDTH) || (y >= ST7789_HEIGHT))
		return; // 检查边界

	ST7789_SetAddressWindow(x, y, x, y); // 设置单个像素的区域
	uint8_t data[2] = { (uint8_t) (color >> 8), (uint8_t) (color & 0xFF) }; // 16位颜色拆分为2字节
	ST7789_WriteData(data, 2); // 写入颜色数据
}

// --- 填充矩形函数 ---
void ST7789_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		const uint16_t *color) {
	if ((x >= ST7789_WIDTH) || (y >= ST7789_HEIGHT))
		return;

	if ((x + w - 1) >= ST7789_WIDTH)
		w = ST7789_WIDTH - x;
	if ((y + h - 1) >= ST7789_HEIGHT)
		h = ST7789_HEIGHT - y;

	ST7789_SetAddressWindow(x, y, x + w - 1, y + h - 1);

	uint32_t total_pixels = (uint32_t) w * h;
	HAL_GPIO_WritePin(ST7789_DC_PORT, ST7789_DC_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_RESET);
	// 一次性发送所有像素数据
	HAL_SPI_Transmit(&hspi1, (uint8_t*) color, total_pixels * 2, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(ST7789_CS_PORT, ST7789_CS_PIN, GPIO_PIN_SET);
}

// --- 填充整个屏幕函数 ---
void ST7789_FillScreen(uint16_t color) {
	ST7789_FillRect(0, 0, ST7789_WIDTH, ST7789_HEIGHT, color);
}

// --- 背光控制函数 ---
void ST7789_SetBacklight(uint8_t enable) {
	if (enable) {
		HAL_GPIO_WritePin(ST7789_BL_PORT, ST7789_BL_PIN, GPIO_PIN_SET); // 开启背光
	} else {
		HAL_GPIO_WritePin(ST7789_BL_PORT, ST7789_BL_PIN, GPIO_PIN_RESET); // 关闭背光
	}
	// 注意：这里的背光控制是简单的开关。如果需要PWM调光，你需要将ST7789_BL_PIN连接到PWM引脚。
}
