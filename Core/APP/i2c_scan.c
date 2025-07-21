/*
 * i2c_scan.c
 *
 *  Created on: Jun 6, 2025
 *      Author: sun
 */
#include "i2c_scan.h"
#include <stdio.h> // 用于 printf

// 你需要确保你的 printf 功能已配置并可用 (例如，通过 USART)

/**
 * @brief  扫描指定的I2C总线，并打印找到的设备地址。
 * @param  hi2c: 指向 I2C_HandleTypeDef 结构体的指针，它包含了I2C外设的配置信息。
 * @retval None
 */
void I2C_ScanDevices(I2C_HandleTypeDef *hi2c) {
	printf("Scanning I2C bus %s...\r\n",
			(hi2c->Instance == I2C1) ? "I2C1" : "I2C2");
	printf("7-bit address | 8-bit address (R/W)\r\n");
	printf("--------------|--------------------\r\n");

	uint8_t address;
	HAL_StatusTypeDef status;
	uint8_t found_devices = 0;

	// 遍历所有可能的 7 位 I2C 地址 (0x00 到 0x7F)
	for (address = 1; address < 127; address++) // 通常排除 0x00 和 0x7F 作为通用地址
			{
		// 尝试发送地址进行写入操作 (8位地址是 7位地址左移一位)
		status = HAL_I2C_IsDeviceReady(hi2c, (uint16_t) (address << 1), 3, 50); // 尝试3次，超时50ms

		if (status == HAL_OK) {
			printf("0x%02X          | 0x%02X (Write)\r\n", address,
					(address << 1));
			found_devices++;
		} else if (status == HAL_ERROR) {
			// HAL_ERROR 可能表示总线上有从机，但可能不应答 IsDeviceReady 的特定操作，
			// 或者表示有其他I2C总线问题。
			// 对于单纯的扫描，我们只关心 HAL_OK。
		} else if (status == HAL_TIMEOUT) {
			// 超时，没有设备响应此地址
		} else if (status == HAL_BUSY) {
			// 总线忙，可以尝试重试或等待
		}
		// 在每次尝试后添加一个短暂的延迟，避免I2C总线过载
		HAL_Delay(1);
	}

	if (found_devices == 0) {
		printf("No I2C devices found.\r\n");
	} else {
		printf("Scan complete. Found %d device(s).\r\n", found_devices);
	}
	printf("\r\n"); // 添加空行以便阅读
}

/**
 * @brief  扫描I2C总线上的设备
 * @param  hi2c: 指向I2C句柄的指针
 * @param  found_addr: 指向一个uint8_t变量的指针，用于存储找到的第一个设备地址 (8位I2C地址)
 * @retval HAL_StatusTypeDef: HAL_OK 表示找到设备，HAL_ERROR 表示未找到或发生错误
 */
HAL_StatusTypeDef I2C_ScanDevices_1(I2C_HandleTypeDef *hi2c,
		uint8_t *found_addr) {
	printf("Scanning I2C bus %s...\r\n",
			(hi2c == &hi2c1) ?
					"I2C1" : ((hi2c == &hi2c2) ? "I2C2" : "Unknown"));
	printf("7-bit address | 8-bit address (R/W)\r\n");
	printf("--------------|--------------------\r\n");

	HAL_StatusTypeDef status = HAL_ERROR; // 默认未找到设备
	*found_addr = 0; // 初始化为0
	for (uint8_t i = 1; i < 128; i++) // I2C 7-bit地址范围从 0x01 到 0x7F
			{
		uint8_t address_8bit_write = i << 1; // 7-bit地址左移一位得到8-bit写地址
		// 尝试发送一个空的写操作（只发送地址，不发送数据），检查ACK
		if (HAL_I2C_Master_Transmit(hi2c, address_8bit_write, NULL, 0, 10)
				== HAL_OK) {
			printf("0x%02X          | 0x%02X (Write)\r\n", i,
					address_8bit_write);
			if (*found_addr == 0) // 只保存找到的第一个地址
					{
				*found_addr = address_8bit_write;
			}
			status = HAL_OK; // 标记为已找到设备
		}
	}
	if (*found_addr != 0) {
		printf("Scan complete. Found 1 device(s) at 0x%02X.\r\n", *found_addr);
	} else {
		printf("Scan complete. Found 0 device(s).\r\n");
	}
	return status;
}

