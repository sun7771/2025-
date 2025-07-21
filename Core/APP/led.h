/*
 * led.h
 *
 *  Created on: Jun 15, 2025
 *      Author: sun
 */

#ifndef APP_LED_H_
#define APP_LED_H_

#include "mybsp.h"

void led_ai_motor_on(void);
void led_ai_motor_off(void);
void led_is_finish_on(void);
void led_is_finish_off(void);
void led_ai_mpu6050_on(void);
void led_ai_mpu6050_off(void);
void led_ai_mpu6050_finish_on(void);
void led_ai_mpu6050_finish_off(void);

#endif /* APP_LED_H_ */
