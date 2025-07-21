/*
 * i2c_scan.h
 *
 *  Created on: Jun 6, 2025
 *      Author: sun
 */

#ifndef I2C_SCANNER_H
#define I2C_SCANNER_H

#include "main.h" // 包含你的HAL库头文件
#include "mybsp.h"
// 扫描指定的I2C总线，并打印找到的设备地址
void I2C_ScanDevices(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef I2C_ScanDevices_1(I2C_HandleTypeDef *hi2c,
		uint8_t *found_addr);

#endif // I2C_SCANNER_H
