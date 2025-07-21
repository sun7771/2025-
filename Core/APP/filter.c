/*
 * filter.c
 *
 *  Created on: Jun 18, 2025
 *      Author: sun
 */
#include "filter.h"
// 初始化
void ComboFilter_Init(ComboFilter_t *f) {
    for(int i=0; i<MEDIAN_N; i++) f->buf[i] = 0;
    f->idx = 0;
    f->count = 0;
    f->last_out = 0;
}

// 中值滤波
float median_filter(float *arr, int n) {
    float temp[MEDIAN_N];
    for(int i=0; i<n; i++) temp[i] = arr[i];
    // 简单冒泡排序
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-1-i; j++)
            if(temp[j] > temp[j+1]) {
                float t = temp[j]; temp[j] = temp[j+1]; temp[j+1] = t;
            }
    return temp[n/2];
}

// 一阶低通+中值滤波
float ComboFilter_Update(ComboFilter_t *f, float new_val, float alpha) {
    // 1. 中值滤波
    f->buf[f->idx] = new_val;
    f->idx = (f->idx + 1) % MEDIAN_N;
    if(f->count < MEDIAN_N) f->count++;
    float median = median_filter(f->buf, f->count);

    // 2. 一阶低通滤波
    f->last_out = alpha * median + (1 - alpha) * f->last_out;
    return f->last_out;
}
