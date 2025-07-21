################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/APP/command.c \
../Core/APP/dht11.c \
../Core/APP/filter.c \
../Core/APP/gt911.c \
../Core/APP/i2c_scan.c \
../Core/APP/led.c \
../Core/APP/motor.c \
../Core/APP/mpu6050.c \
../Core/APP/st7789.c \
../Core/APP/task.c 

OBJS += \
./Core/APP/command.o \
./Core/APP/dht11.o \
./Core/APP/filter.o \
./Core/APP/gt911.o \
./Core/APP/i2c_scan.o \
./Core/APP/led.o \
./Core/APP/motor.o \
./Core/APP/mpu6050.o \
./Core/APP/st7789.o \
./Core/APP/task.o 

C_DEPS += \
./Core/APP/command.d \
./Core/APP/dht11.d \
./Core/APP/filter.d \
./Core/APP/gt911.d \
./Core/APP/i2c_scan.d \
./Core/APP/led.d \
./Core/APP/motor.d \
./Core/APP/mpu6050.d \
./Core/APP/st7789.d \
./Core/APP/task.d 


# Each subdirectory must supply rules for building sources it contributes
Core/APP/%.o Core/APP/%.su Core/APP/%.cyclo: ../Core/APP/%.c Core/APP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-APP

clean-Core-2f-APP:
	-$(RM) ./Core/APP/command.cyclo ./Core/APP/command.d ./Core/APP/command.o ./Core/APP/command.su ./Core/APP/dht11.cyclo ./Core/APP/dht11.d ./Core/APP/dht11.o ./Core/APP/dht11.su ./Core/APP/filter.cyclo ./Core/APP/filter.d ./Core/APP/filter.o ./Core/APP/filter.su ./Core/APP/gt911.cyclo ./Core/APP/gt911.d ./Core/APP/gt911.o ./Core/APP/gt911.su ./Core/APP/i2c_scan.cyclo ./Core/APP/i2c_scan.d ./Core/APP/i2c_scan.o ./Core/APP/i2c_scan.su ./Core/APP/led.cyclo ./Core/APP/led.d ./Core/APP/led.o ./Core/APP/led.su ./Core/APP/motor.cyclo ./Core/APP/motor.d ./Core/APP/motor.o ./Core/APP/motor.su ./Core/APP/mpu6050.cyclo ./Core/APP/mpu6050.d ./Core/APP/mpu6050.o ./Core/APP/mpu6050.su ./Core/APP/st7789.cyclo ./Core/APP/st7789.d ./Core/APP/st7789.o ./Core/APP/st7789.su ./Core/APP/task.cyclo ./Core/APP/task.d ./Core/APP/task.o ./Core/APP/task.su

.PHONY: clean-Core-2f-APP

