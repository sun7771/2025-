/*
 * task.c
 *
 *  Created on: Apr 26, 2025
 *      Author: sun
 *      目前的模型是编码器值35所得的
 */
#include "task.h"

const float knowledge_motor[31] = { 20.000000000000f, 0.353980481625f,
		0.353980481625f, 1.000000000000f, 3.000000000000f, 1.375000000000f,
		0.216000005603f, 0.527000010014f, 33.333332061768f, 7.453558921814f,
		33.333332061768f, 7.453558921814f, 33.333332061768f, 7.453558921814f,
		33.333332061768f, 7.453558921814f, 18.000000000000f, 5.000000000000f,
		4.000000000000f, 1.000000000000f, 1.000000000000f, 0.000000000000f,
		0.000000000000f, 0.000000000000f, 14.000000000000f, 2.000000000000f,
		0.000000000000f, 0.000000000000f, 1000000.000000000000f,
		0.000000000000f, 2.000000000000f };
const float knowledge_mpu6050[19] = { 37.000000000000f, 2.000000000000f,
		0.000000000000f, 0.000000000000f, 0.000000000000f, 7.000000000000f,
		1.000000000000f, 1.000000000000f, 0.000000000000f, 0.000000000000f,
		0.000000000000f, 0.000000000000f, 100.000000000000f, 0.000000000000f,
		0.000000000000f, 0.000000000000f, 1000000.000000000000f,
		0.000000000000f, 98.000000000000f };

// MPU6050参数
float roll, pitch, yaw, dt = 0.01f;
uint8_t ID;

// 电机的AI异常检测
uint8_t similarity_motor;
uint8_t learn_flag_motor = 0;
uint16_t count_motor = 0;
uint16_t count_detect_motor = 0; // 调试用的
float ai_motor_buff[4];
uint8_t motor_lock = 0;
uint8_t mpu6050_lock = 0;
uint8_t alock = 0;
// 货物的异常检测
uint8_t similarity_mpu6050;
uint8_t learn_flag_mpu6050 = 0;
uint16_t count_mpu6050 = 0;
uint16_t count_detect_mpu6050 = 0; // 调试用的
float ai_mpu6050_buff[1];

// 对mpu6050和dht11的异常检测

// 串口

char readbuff[200];
char read_esp8266[50];
float current_roll, current_pitch, current_yaw;
uint8_t commandlength = 0;
char msg[500];
float filtered_roll, filtered_pitch, filtered_yaw;
static ComboFilter_t roll_filter, pitch_filter, yaw_filter;

// 电机
int speed1 , speed2 , speed3 , speed4 , raw1, raw2, raw3, raw;
volatile static uint8_t motor_run_flag = 1;
static Filter_t speed1_fifter, speed2_fifter, speed3_fifter, speed4_fifter;
uint8_t motor_stable = 1;
// dht11
float humi, temp;

// 设置运行时间
uint32_t ai_mpu6050_tick = 0;
uint32_t encoder_tick = 0;
uint32_t dht11_tick = 0;
uint32_t send_tick = 0;
uint32_t ai_motor_tick = 0;

// 显示
uint8_t is_on_abnormal_screen = 0, lock = 1;
uint8_t button_stop = 0;

/*@外设初始化
 *
 */
void peri_init(void) {
	// DHT11一定要开时钟提供 延时函数
	DHT11_Init();
	HAL_TIM_Base_Start(&htim6);
	neai_anomalydetection_init_motor();
	//	neai_anomalydetection_knowledge_motor(knowledge_motor);
	neai_anomalydetection_init_mpu6050();
	neai_anomalydetection_knowledge_mpu6050(knowledge_mpu6050);

	// 开启PWM模式
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

	// 串口
	HAL_UARTEx_ReceiveToIdle_IT(&huart5, (uint8_t*) readbuff, sizeof(readbuff));
	HAL_UARTEx_ReceiveToIdle_IT(&huart3, (uint8_t*) read_esp8266,
			sizeof(read_esp8266));

	// 获取编码器的值
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL);

	filter_init(&speed1_fifter);
	filter_init(&speed2_fifter);
	filter_init(&speed3_fifter);
	filter_init(&speed4_fifter);
	// LVGL初始化
	lv_init();
	printf("1\n");
	lv_port_disp_init();
	printf("2\n");
	lv_port_indev_init();
	printf("3\n");
	// MPU6050滤波
	ComboFilter_Init(&roll_filter);
	ComboFilter_Init(&pitch_filter);
	ComboFilter_Init(&yaw_filter);
}

/*@AI检测异常
 *
 */
void ai_proc_motor(void) {
	if (uwTick - ai_motor_tick < 10)
		return;
	ai_motor_tick = uwTick;
	ai_motor_buff[0] = speed1;
	ai_motor_buff[1] = speed2;
	ai_motor_buff[2] = speed3;
	ai_motor_buff[3] = speed4;

	if (learn_flag_motor == 0) {
		neai_anomalydetection_learn_motor(ai_motor_buff);
		count_motor++;
		led_is_finish_on();
	}
	if (count_motor > 800) {
		learn_flag_motor = 1;
		led_is_finish_off();
		count_motor = 0;
	}//90 91
	if (learn_flag_motor == 1) {
		neai_anomalydetection_detect_motor(ai_motor_buff, &similarity_motor);
		count_detect_motor++;
		if (similarity_motor > 75 ) {
			led_ai_motor_on();
			motor_run_flag = 1;
			motor_lock = 0;
		} else {
			motor_lock = 1;
			sprintf(msg,"S");
		    HAL_UART_Transmit(&huart3, (uint8_t*) msg, strlen(msg), 100); // 和ESP8266通信
			led_ai_motor_off();
			motor_run_flag = 0;
			if (lock == 1) {
				is_on_abnormal_screen = 1;
				lock = 0;
			}
		}
	}
}

void ai_proc_mpu6050(void) {
	if (uwTick - ai_mpu6050_tick < 10)
		return;
	ai_mpu6050_tick = uwTick;
	ai_mpu6050_buff[0] = filtered_yaw;

	if (learn_flag_mpu6050 == 0) {
		neai_anomalydetection_learn_mpu6050(ai_mpu6050_buff);
		count_mpu6050++;
		led_ai_mpu6050_finish_on();
	}
	if (count_mpu6050 > 300) {
		learn_flag_mpu6050 = 1;
		count_mpu6050 = 0;
		led_ai_mpu6050_finish_off();
	}
	if (learn_flag_mpu6050 == 1) {
		neai_anomalydetection_detect_mpu6050(ai_mpu6050_buff,
				&similarity_mpu6050);
		if (similarity_mpu6050 > 80) {
			led_ai_mpu6050_on();
			motor_run_flag = 1;
			mpu6050_lock = 0;
		} else {
			mpu6050_lock = 1;
			led_ai_mpu6050_off();
			motor_run_flag = 0;
			sprintf(msg,"S");
			HAL_UART_Transmit(&huart3, (uint8_t*) msg, strlen(msg), 100); // 和ESP8266通信
			if (lock == 1) {
				is_on_abnormal_screen = 1;
				lock = 0;
			}
		}
	}
}

/*@电机转动函数
 *
 */

void motor_proc(void) {
	// 只要有一个锁，或者button_stop，电机就停
	if (motor_lock || mpu6050_lock || button_stop || alock) {
		motor_stop();
	} else {
		motor1_forward(30);
		motor2_forward(30);
		motor3_forward(30);
		motor4_forward(30);
	}
	if (motor_stable == 1) {
		HAL_Delay(1000);
		motor_stable = 0;
	}
}

/*@获取编码器的值
 *
 */

int speed1_last ,speed2_last ,speed3_last,speed4_last  ;
void fi_dt(float_t a , int *speed,int *speed_last)
{
	*speed = a * (*speed) + (1-a) * (*speed_last) +30 ;
	
	// 添加上限限制，防止速度值无限增长
	if (*speed > 100) {
		*speed = 100;
	}
	if (*speed < 0) {
		*speed = 0;
	}
	
	*speed_last =*speed;
	if(*speed > 80) *speed = 80;
}




void encoder_proc(void) {
	if (uwTick - encoder_tick < 10)
		return;
	encoder_tick = uwTick;
	int val;

	val = filter_update(&speed1_fifter, read_speed(&htim3));
	if (val != -1)
		speed1 = -val;

	val = filter_update(&speed2_fifter, read_speed(&htim4));
	if (val != -1)
		speed2 = val;

	val = filter_update(&speed3_fifter, read_speed(&htim5));
	if (val != -1)
		speed3 = -val;

	val = filter_update(&speed4_fifter, read_speed(&htim8));
	if (val != -1)
		speed4 = -val;

//	if (speed1 > 30 && speed1 < 80)
//		speed1 = 60;
//	if (speed2 > 30 && speed2 < 80)
//		speed2 = 60;
//	if (speed3 > 30 && speed3 < 80)
//		speed3 = 60;
//	if (speed4 > 30 && speed4 < 80)
//		speed4 = 60;
	fi_dt(0.5, &speed1, &speed1_last);
	fi_dt(0.5, &speed2, &speed2_last);
	fi_dt(0.5, &speed3, &speed3_last);
	fi_dt(0.5, &speed4, &speed4_last);

}

/*@获取温湿度值
 *
 */
void dht911_proc(void) {
	if (uwTick - dht11_tick < 100)
		return;
	dht11_tick = uwTick;
	// 调试用下面的
	//    if (DHT11_ReadData(&temp, &humi) == 0) {
	//        printf("%.2f,%.2f\n", temp, humi);
	//    } else {
	//        printf("DHT11 error\n");
	//    }

	DHT11_ReadData(&temp, &humi);
}

/*@串口中断函数
 *
 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
	if (huart == &huart5) {
		Command_Write((uint8_t*) readbuff, Size);
		HAL_UARTEx_ReceiveToIdle_IT(&huart5, (uint8_t*) readbuff,
				(uint16_t) sizeof(readbuff));
	}
	if (huart == &huart3) {
		read_esp8266[
				Size < sizeof(read_esp8266) ? Size : sizeof(read_esp8266) - 1] =
				'\0'; // 保证字符串结尾
		if (strcmp(read_esp8266, "end") == 0) {
			alock = 1;
		}
		HAL_UARTEx_ReceiveToIdle_IT(&huart3, (uint8_t*) readbuff,
								(uint16_t) sizeof(readbuff));
	}
}

/*@训练模型的数据集
 *
 */
void serial_send(void) {
	if (uwTick - send_tick < 10)
		return;
	send_tick = uwTick;
	commandlength = Command_GetFloatData(&current_roll, &current_pitch,
			&current_yaw);
	if (commandlength == 3) {
		//		printf("%.2f,%.2f,%.2f\n", current_roll, current_pitch, current_yaw); // 和电脑通信
		filtered_roll = ComboFilter_Update(&roll_filter, current_roll, 0.2f); // alpha=0.2
		filtered_pitch = ComboFilter_Update(&pitch_filter, current_pitch, 0.2f);
		filtered_yaw = ComboFilter_Update(&yaw_filter, current_yaw, 0.2f);
		sprintf(msg, "A%d_%d_%d_%d_%.2f_%.2f_%.2f_%.2f_%.2fe", speed1, speed2,
				speed3, speed4, filtered_yaw, filtered_pitch, filtered_roll,
				humi, temp);
		HAL_UART_Transmit(&huart3, (uint8_t*) msg, strlen(msg), 100); // 和ESP8266通信
	}
	//	printf("%.2f,%d",filtered_yaw,similarity_motor);3
	if (filtered_yaw < 2 && filtered_yaw > -2) {
		filtered_yaw = 0;
	}

}

void check_similarity_and_switch_screen(lv_ui *ui) {

	if (ui->screen_3 == NULL) {
		setup_scr_screen_3(ui);
	}
	lv_scr_load(ui->screen_3);

	// 你可以根据需要添加else分支
}

/*@全部任务的入口
 *
 */
void task_proc(void) {
	dht911_proc();
	motor_proc();
	encoder_proc();
	serial_send();

	ai_proc_motor();
	ai_proc_mpu6050();
	if (is_on_abnormal_screen == 1) {
		is_on_abnormal_screen = 0;
		check_similarity_and_switch_screen(&guider_ui);
	}
}
