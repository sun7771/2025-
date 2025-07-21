/*
 * motor.c
 *
 *  Created on: Apr 27, 2025
 *      Author: sun
 */

#include "motor.h"

#define motor1_port GPIOA
#define motor1_PIN1 GPIO_PIN_4
#define motor1_PIN2 GPIO_PIN_5

#define motor2_port GPIOA
#define motor2_PIN1 GPIO_PIN_6
#define motor2_PIN2 GPIO_PIN_7

#define motor3_port GPIOC
#define motor3_PIN1 GPIO_PIN_4
#define motor3_PIN2 GPIO_PIN_5

#define motor4_port GPIOB
#define motor4_PIN1 GPIO_PIN_0
#define motor4_PIN2 GPIO_PIN_1

void motor1_forward(uint8_t speed) {
	HAL_GPIO_WritePin(motor1_port, motor1_PIN1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor1_port, motor1_PIN2, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);

}
void motor1_back(uint8_t speed) {
	HAL_GPIO_WritePin(motor1_port, motor1_PIN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor1_port, motor1_PIN2, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);

}

void motor2_forward(uint8_t speed) {
	HAL_GPIO_WritePin(motor2_port, motor2_PIN1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor2_port, motor2_PIN2, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);

}
void motor2_back(uint8_t speed) {
	HAL_GPIO_WritePin(motor2_port, motor2_PIN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor2_port, motor2_PIN2, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);

}

void motor3_forward(uint8_t speed) {
	HAL_GPIO_WritePin(motor3_port, motor3_PIN1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor3_port, motor3_PIN2, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speed);

}
void motor3_back(uint8_t speed) {
	HAL_GPIO_WritePin(motor3_port, motor3_PIN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor3_port, motor3_PIN2, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speed);

}

void motor4_forward(uint8_t speed) {
	HAL_GPIO_WritePin(motor4_port, motor4_PIN1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(motor4_port, motor4_PIN2, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speed);

}
void motor4_back(uint8_t speed) {
	HAL_GPIO_WritePin(motor4_port, motor4_PIN1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(motor4_port, motor4_PIN2, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speed);

}

int read_speed(TIM_HandleTypeDef *htim) {
	int temp;
	temp = (short) __HAL_TIM_GetCounter(htim);
	__HAL_TIM_SetCounter(htim,0);
	return temp;
}

void motor_stop(void) {
	motor1_forward(0);
	motor2_forward(0);
	motor3_forward(0);
	motor4_forward(0);
}

void filter_init(Filter_t *f)
{
	for (int i = 0 ; i < SPEED_FILTER_N; i++) f->buf[i]=0;
	f->count = 0;
	f->idx = 0;
	f->sum = 0;
}

int filter_update(Filter_t *f, int new_val) {
    f->sum -= f->buf[f->idx];
    f->buf[f->idx] = new_val;
    f->sum += new_val;
    f->idx = (f->idx + 1) % SPEED_FILTER_N;
    if(f->count < SPEED_FILTER_N) {
        f->count++;
        return -1; // 未收集满，不输出
    }
    return f->sum / SPEED_FILTER_N; // 收集满5个，输出平均
}






