#ifndef ST7789_H
#define ST7789_H

#include "main.h"       // 包含你的HAL库头文件，如 stm32u5xx_hal.h
#include <stdint.h>     // For uint16_t, uint8_t etc.
#include <stddef.h>     // For size_t
#include "mybsp.h"
// --- ST7789 SPI 句柄 ---
extern SPI_HandleTypeDef hspi1; // 假设你使用 SPI1，请确保在 main.c 中声明为 extern

// --- ST7789 GPIO 配置宏定义 ---
// !!! 注意：以下宏定义中的 YOUR_GPIOx_PORT 和 YOUR_GPIO_PIN_y 需要你根据你的硬件原理图自行替换 !!!
// 例如：如果 GPIO_NUM_13 对应 PB13, 则替换为 GPIOB 和 GPIO_PIN_13

// 背光 (BL) 引脚：配置为 GPIO_Output
#define ST7789_BL_PORT          GPIOE // 例如：GPIOB
#define ST7789_BL_PIN           GPIO_PIN_12   // 例如：GPIO_PIN_13

// 片选 (CS) 引脚：配置为 GPIO_Output
#define ST7789_CS_PORT          GPIOD // 例如：GPIOC
#define ST7789_CS_PIN           GPIO_PIN_9   // 例如：GPIO_PIN_11

// 数据/命令 (DC) 引脚：配置为 GPIO_Output
#define ST7789_DC_PORT          GPIOD // 例如：GPIOD
#define ST7789_DC_PIN           GPIO_PIN_10   // 例如：GPIO_PIN_10

// 复位 (RST) 引脚：配置为 GPIO_Output
#define ST7789_RST_PORT         GPIOD  // 例如：GPIOE
#define ST7789_RST_PIN          GPIO_PIN_11  // 例如：GPIO_PIN_3

// SPI CLK 和 MOSI 引脚是由你选择的 SPI 外设（例如 hspi1）自动管理的，
// 你无需在这里定义它们的 GPIO 端口和引脚宏。

// LCD 分辨率
#define ST7789_WIDTH            320
#define ST7789_HEIGHT           240

// 颜色定义 (RGB565 格式)
#define ST7789_COLOR_BLACK      0x0000
#define ST7789_COLOR_NAVY       0x000F
#define ST7789_COLOR_DARKGREEN  0x03E0
#define ST7789_COLOR_DARKCYAN   0x03EF
#define ST7789_COLOR_MAROON     0x7800
#define ST7789_COLOR_PURPLE     0x780F
#define ST7789_COLOR_OLIVE      0x7BE0
#define ST7789_COLOR_LIGHTGREY  0xC618
#define ST7789_COLOR_DARKGREY   0x7BEF
#define ST7789_COLOR_BLUE       0x001F
#define ST7789_COLOR_GREEN      0x07E0
#define ST7789_COLOR_CYAN       0x07FF
#define ST7789_COLOR_RED        0xF800
#define ST7789_COLOR_MAGENTA    0xF81F
#define ST7789_COLOR_YELLOW     0xFFE0
#define ST7789_COLOR_WHITE      0xFFFF
#define ST7789_COLOR_ORANGE     0xFD20
#define ST7789_COLOR_GREENYELLOW 0xAFE5
#define ST7789_COLOR_PINK       0xF81F

// --- ST7789 函数声明 ---
void ST7789_Init(void);
void ST7789_SetBacklight(uint8_t enable); // 简单开关背光 (1:开, 0:关)
void ST7789_SetAddressWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void ST7789_WriteCommand(uint8_t cmd);
void ST7789_WriteData(uint8_t *buff, size_t buff_size);
void ST7789_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
// ...existing code...
void ST7789_FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		const uint16_t *color);
// ...existing code...
void ST7789_FillScreen(uint16_t color);

#endif // ST7789_H
