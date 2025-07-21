/*
 * motor.h
 *
 *  Created on: Apr 27, 2025
 *      Author: sun
 */

#ifndef APP_MOTOR_H_
#define APP_MOTOR_H_

#include "mybsp.h"
void motor1_forward(uint8_t speed);
void motor1_back(uint8_t speed);

void motor2_forward(uint8_t speed);
void motor2_back(uint8_t speed);

void motor3_forward(uint8_t speed);
void motor3_back(uint8_t speed);

void motor4_forward(uint8_t speed);
void motor4_back(uint8_t speed);

void motor_stop(void);

int read_speed(TIM_HandleTypeDef *htim);

#define SPEED_FILTER_N 85

typedef struct {
	int buf[SPEED_FILTER_N];
	int idx;
	int sum;
	int count;
} Filter_t;
#endif /* APP_MOTOR_H_ */
