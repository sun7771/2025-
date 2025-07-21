/*
 * dht11.h
 *
 *  Created on: Jun 12, 2025
 *      Author: sun
 */

#ifndef APP_DHT11_H_
#define APP_DHT11_H_

#include "mybsp.h"
void DHT11_Init(void);
uint8_t DHT11_ReadData(float *temperature, float *humidity);

#endif /* APP_DHT11_H_ */
