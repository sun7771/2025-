/*
 * led.c
 *
 *  Created on: Jun 15, 2025
 *      Author: sun
 */
#include "led.h"

#define led_is_finish_port GPIOD
#define led_is_finish_pin GPIO_PIN_0

#define led_ai_motor_port GPIOD
#define led_ai_motor_pin GPIO_PIN_1


#define led_ai_mpu6050_finish_port GPIOD
#define led_ai_mpu6050_finish_pin GPIO_PIN_3


#define led_ai_mpu6050_port GPIOD
#define led_ai_mpu6050_pin GPIO_PIN_4


void led_ai_motor_on(void) {
	HAL_GPIO_WritePin(led_ai_motor_port, led_ai_motor_pin, GPIO_PIN_SET);
}

void led_ai_motor_off(void) {
	HAL_GPIO_WritePin(led_ai_motor_port, led_ai_motor_pin, GPIO_PIN_RESET);
}


void led_is_finish_on(void) {
	HAL_GPIO_WritePin(led_is_finish_port, led_is_finish_pin, GPIO_PIN_SET);
}

void led_is_finish_off(void) {
	HAL_GPIO_WritePin(led_is_finish_port, led_is_finish_pin, GPIO_PIN_RESET);
}



void led_ai_mpu6050_on(void) {
	HAL_GPIO_WritePin(led_ai_mpu6050_port, led_ai_mpu6050_pin, GPIO_PIN_SET);
}

void led_ai_mpu6050_off(void) {
	HAL_GPIO_WritePin(led_ai_mpu6050_port, led_ai_mpu6050_pin, GPIO_PIN_RESET);
}






void led_ai_mpu6050_finish_on(void)
{
	HAL_GPIO_WritePin(led_ai_mpu6050_finish_port, led_ai_mpu6050_finish_pin, GPIO_PIN_SET);
}

void led_ai_mpu6050_finish_off(void)
{
	HAL_GPIO_WritePin(led_ai_mpu6050_finish_port, led_ai_mpu6050_finish_pin, GPIO_PIN_RESET);
}





