#include "command.h" // 确保这里包含了必要的头文件，例如 <string.h> 和 <stdio.h>

// 移除 COMMAND_MIN_LENGTH，因为它与文本协议不符
// #define COMMAND_MIN_LENGTH 4

// 循环缓冲区大小
#define BUFFER_SIZE 1000
// 循环缓冲区
uint8_t buffer[BUFFER_SIZE];
// 循环缓冲区读索引
uint8_t readIndex = 0;
// 循环缓冲区写索引
uint8_t writeIndex = 0;

/**
 * @brief 增加读索引
 * @param length 要增加的长度
 */
void Command_AddReadIndex(uint8_t length) {
  readIndex += length;
  readIndex %= BUFFER_SIZE;
}

/**
 * @brief 读取第i位数据 超过缓存区长度自动循环
 * @param i 要读取的数据索引
 */
uint8_t Command_Read(uint8_t i) {
  uint8_t index = i % BUFFER_SIZE;
  return buffer[index];
}

/**
 * @brief 计算未处理的数据长度
 * @return 未处理的数据长度
 * @retval 0 缓冲区为空
 * @retval 1~BUFFER_SIZE-1 未处理的数据长度
 * @retval BUFFER_SIZE 缓冲区已满
 */
uint8_t Command_GetLength() {
	return (writeIndex + BUFFER_SIZE - readIndex) % BUFFER_SIZE;
}

/**
 * @brief 计算缓冲区剩余空间
 * @return 剩余空间
 * @retval 0 缓冲区已满
 * @retval 1~BUFFER_SIZE-1 剩余空间
 * @retval BUFFER_SIZE 缓冲区为空
 */
uint8_t Command_GetRemain() {
  return BUFFER_SIZE - Command_GetLength();
}

/**
 * @brief 向缓冲区写入数据
 * @param data 要写入的数据指针
 * @param length 要写入的数据长度
 * @return 写入的数据长度
 */
uint8_t Command_Write(uint8_t *data, uint8_t length) {
  // 如果缓冲区不足 则不写入数据 返回0
  if (Command_GetRemain() < length) {
    return 0;
  }
  // 使用memcpy函数将数据写入缓冲区
  if (writeIndex + length < BUFFER_SIZE) {
    memcpy(buffer + writeIndex, data, length);
    writeIndex += length;
  } else {
    uint8_t firstLength = BUFFER_SIZE - writeIndex;
    memcpy(buffer + writeIndex, data, firstLength);
    memcpy(buffer, data + firstLength, length - firstLength);
    writeIndex = length - firstLength;
  }
  return length;
}

/**
 * @brief 尝试获取并解析一条包含roll, pitch, yaw的文本指令
 * 假定数据格式为 "%.2f,%.2f,%.2f\n"，以换行符 '\n' 结束。
 * @param roll_ptr 指向存储roll值的浮点数指针
 * @param pitch_ptr 指向存储pitch值的浮点数指针
 * @param yaw_ptr 指向存储yaw值的浮点数指针
 * @return 成功解析的浮点数个数（期望为3），如果未找到完整指令或解析失败则返回0
 */
uint8_t Command_GetFloatData(float *roll_ptr, float *pitch_ptr, float *yaw_ptr) {
  // 临时缓冲区，用于存储从循环缓冲区中提取的文本行
  // 考虑到最长可能的浮点数表示（例如 -XXX.YY\n），加上逗号和结束符，BUFFER_SIZE 是足够的
  char temp_line[BUFFER_SIZE];
  uint8_t current_data_length = Command_GetLength();

  // 如果缓冲区为空，直接返回
  if (current_data_length == 0) {
    return 0;
  }

  // 在当前有效数据中查找换行符 '\n'
  uint8_t line_end_offset = 0; // 记录 '\n' 相对于 readIndex 的偏移
  for (uint8_t i = 0; i < current_data_length; i++) {
    // Command_Read(readIndex + i) 会处理循环读取
    if (Command_Read(readIndex + i) == '\n') {
      line_end_offset = i;
      break; // 找到换行符，跳出循环
    }
  }

  // 如果没有找到换行符，说明没有完整的文本行
  if (line_end_offset == 0 && Command_Read(readIndex) != '\n' && current_data_length > 0) {
      return 0; // 没有找到换行符，并且当前数据不是一个单独的换行符
  }

  // 计算完整文本行的长度（包括 '\n'）
  uint8_t line_length = line_end_offset + 1;

  // 将完整的文本行从循环缓冲区复制到临时缓冲区
  for (uint8_t i = 0; i < line_length; i++) {
    temp_line[i] = Command_Read(readIndex + i);
  }
  temp_line[line_length] = '\0'; // 确保字符串以 null 终止

  // 使用 sscanf 解析字符串
  int parsed_count = sscanf(temp_line, "%f,%f,%f", roll_ptr, pitch_ptr, yaw_ptr);

  // 无论解析是否成功，都将已处理的数据从循环缓冲区中移除
  Command_AddReadIndex(line_length);

  // 如果成功解析了3个浮点数，则返回3
  if (parsed_count == 3) {
    return 3;
  } else {
    // 如果解析失败（例如格式不符），返回0
    return 0;
  }
}
