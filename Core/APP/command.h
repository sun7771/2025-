#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#include "main.h"
#include <string.h>

uint8_t Command_Write(uint8_t *data, uint8_t length);

uint8_t Command_GetFloatData(float *roll_ptr, float *pitch_ptr, float *yaw_ptr);

#endif /* INC_COMMAND_H_ */
