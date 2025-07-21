#include "mpu6050.h"
#include <math.h>

#define M_PI 3.1415926
#define MPU6050_DATA_LEN 14

extern I2C_HandleTypeDef hi2c1; // I2C2句柄
#define i2c_port hi2c1
//定义
float gyroX_bias = 0.0f;
float gyroY_bias = 0.0f;
float gyroZ_bias = 0.0f;
static float yaw_angle = 0.0f;
float yaw_drift = 0.0f;
float yaw_drift_alpha = 0.005f;

static uint8_t mpu6050_dma_buffer[MPU6050_DATA_LEN];
static volatile uint8_t mpu6050_dma_ready = 0;

// 写寄存器
void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data) {
	uint8_t data[2] = { RegAddress, Data };
	if (HAL_I2C_Master_Transmit(&i2c_port, MPU6050_ADDRESS, data, 2,
			HAL_MAX_DELAY) != HAL_OK) {
		Error_Handler();
	}
}

// 读寄存器
uint8_t MPU6050_ReadReg(uint8_t RegAddress) {
	uint8_t data;
	if (HAL_I2C_Master_Transmit(&i2c_port, MPU6050_ADDRESS, &RegAddress, 1,
	HAL_MAX_DELAY) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_I2C_Master_Receive(&i2c_port, MPU6050_ADDRESS, &data, 1,
			HAL_MAX_DELAY) != HAL_OK) {
		Error_Handler();
	}
	return data;
}

// 获取ID
uint8_t MPU6050_GetID(void) {
	return MPU6050_ReadReg(MPU6050_WHO_AM_I);
}

// 初始化
void MPU6050_Init(void) {
	MPU6050_WriteReg(MPU6050_PWR_MGMT_1, 0x01);
	MPU6050_WriteReg(MPU6050_PWR_MGMT_2, 0x00);
	MPU6050_WriteReg(MPU6050_SMPLRT_DIV, 0x09);
	MPU6050_WriteReg(MPU6050_CONFIG, 0x06);
	MPU6050_WriteReg(MPU6050_GYRO_CONFIG, 0x18);
	MPU6050_WriteReg(MPU6050_ACCEL_CONFIG, 0x18);
}

// 开始DMA读取
void MPU6050_RequestData_DMA(void) {
	if (HAL_I2C_Mem_Read_DMA(&i2c_port, MPU6050_ADDRESS, MPU6050_ACCEL_XOUT_H,
	I2C_MEMADD_SIZE_8BIT, mpu6050_dma_buffer, MPU6050_DATA_LEN) != HAL_OK) {
		Error_Handler();
	}
}

// DMA完成回调（需在main.c中调用）
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c) {
	if (hi2c->Instance == hi2c->Instance) {
		mpu6050_dma_ready = 1;
	}
}

// 判断DMA是否完成
uint8_t MPU6050_IsDataReady(void) {
	return mpu6050_dma_ready;
}

// 解析DMA数据
void MPU6050_ParseData(int16_t *AccX, int16_t *AccY, int16_t *AccZ,
		int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ) {
	if (!mpu6050_dma_ready)
		return;

	*AccX = (int16_t) ((mpu6050_dma_buffer[0] << 8) | mpu6050_dma_buffer[1]);
	*AccY = (int16_t) ((mpu6050_dma_buffer[2] << 8) | mpu6050_dma_buffer[3]);
	*AccZ = (int16_t) ((mpu6050_dma_buffer[4] << 8) | mpu6050_dma_buffer[5]);
	*GyroX = (int16_t) ((mpu6050_dma_buffer[8] << 8) | mpu6050_dma_buffer[9]);
	*GyroY = (int16_t) ((mpu6050_dma_buffer[10] << 8) | mpu6050_dma_buffer[11]);
	*GyroZ = (int16_t) ((mpu6050_dma_buffer[12] << 8) | mpu6050_dma_buffer[13]);

	mpu6050_dma_ready = 0;
}

// 校准陀螺仪偏移
void MPU6050_CalibrateGyroBias(void) {
	int32_t sumX = 0, sumY = 0, sumZ = 0;
	int16_t gx, gy, gz;
	const int samples = 500;

	for (int i = 0; i < samples; i++) {
		int16_t dummyAx, dummyAy, dummyAz;
		MPU6050_GetData(&dummyAx, &dummyAy, &dummyAz, &gx, &gy, &gz);
		sumX += gx;
		sumY += gy;
		sumZ += gz;
		HAL_Delay(2);
	}

	gyroX_bias = (float) sumX / samples;
	gyroY_bias = (float) sumY / samples;
	gyroZ_bias = (float) sumZ / samples;
}

// 同步方式获取数据（不使用DMA）
void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ,
		int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ) {
	uint8_t DataH, DataL;								//定义数据高8位和低8位的变量

	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H);		//读取加速度计X轴的高8位数据
	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_L);		//读取加速度计X轴的低8位数据
	*AccX = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回

	DataH = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_H);		//读取加速度计Y轴的高8位数据
	DataL = MPU6050_ReadReg(MPU6050_ACCEL_YOUT_L);		//读取加速度计Y轴的低8位数据
	*AccY = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回

	DataH = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_H);		//读取加速度计Z轴的高8位数据
	DataL = MPU6050_ReadReg(MPU6050_ACCEL_ZOUT_L);		//读取加速度计Z轴的低8位数据
	*AccZ = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回

	DataH = MPU6050_ReadReg(MPU6050_GYRO_XOUT_H);		//读取陀螺仪X轴的高8位数据
	DataL = MPU6050_ReadReg(MPU6050_GYRO_XOUT_L);		//读取陀螺仪X轴的低8位数据
	*GyroX = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回

	DataH = MPU6050_ReadReg(MPU6050_GYRO_YOUT_H);		//读取陀螺仪Y轴的高8位数据
	DataL = MPU6050_ReadReg(MPU6050_GYRO_YOUT_L);		//读取陀螺仪Y轴的低8位数据
	*GyroY = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回

	DataH = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_H);		//读取陀螺仪Z轴的高8位数据
	DataL = MPU6050_ReadReg(MPU6050_GYRO_ZOUT_L);		//读取陀螺仪Z轴的低8位数据
	*GyroZ = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回
}
// 欧拉角（兼容DMA）
void MPU6050_GetEulerAngle_Comp(float *roll, float *pitch, float *yaw, float dt) {
	int16_t accX, accY, accZ;
	int16_t gyroX, gyroY, gyroZ;

	if (mpu6050_dma_ready) {
		MPU6050_ParseData(&accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ);
	} else {
		MPU6050_GetData(&accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ);
	}

	float ax = (float) accX / 2048.0f;
	float ay = (float) accY / 2048.0f;
	float az = (float) accZ / 2048.0f;

	float gx = ((float) gyroX - gyroX_bias) / 16.4f;
	float gy = ((float) gyroY - gyroY_bias) / 16.4f;
	float gz = ((float) gyroZ - gyroZ_bias) / 16.4f;

	float accRoll = atan2f(ay, az) * 180.0f / M_PI;
	float accPitch = atan2f(-ax, sqrtf(ay * ay + az * az)) * 180.0f / M_PI;

	static float roll_angle = 0.0f;
	static float pitch_angle = 0.0f;
	float alpha = 0.98f;

	roll_angle = alpha * (roll_angle + gx * dt) + (1 - alpha) * accRoll;
	pitch_angle = alpha * (pitch_angle + gy * dt) + (1 - alpha) * accPitch;

	yaw_angle += gz * dt;

	*roll = roll_angle;
	*pitch = pitch_angle;
	*yaw = yaw_angle;
}

