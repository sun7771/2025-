/*
 * filter.h
 *
 *  Created on: Jun 18, 2025
 *      Author: sun
 */

#ifndef APP_FILTER_H_
#define APP_FILTER_H_

#include "mybsp.h"

#define MEDIAN_N 5  // 中值滤波窗口大小

typedef struct {
    float buf[MEDIAN_N];
    int idx;
    int count;
    float last_out; // 上一次低通滤波输出
} ComboFilter_t;

void ComboFilter_Init(ComboFilter_t *f);
float median_filter(float *arr, int n);
float ComboFilter_Update(ComboFilter_t *f, float new_val, float alpha);

#endif /* APP_FILTER_H_ */
