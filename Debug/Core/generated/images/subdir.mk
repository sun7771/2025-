################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/generated/images/_1_alpha_40x40.c \
../Core/generated/images/_2_alpha_40x40.c \
../Core/generated/images/_3_alpha_40x40.c \
../Core/generated/images/_GOP_TestCenter_LeftNav_Icon_alpha_40x40.c \
../Core/generated/images/_QS_alpha_219x92.c \
../Core/generated/images/_QS_alpha_307x91.c \
../Core/generated/images/_QS_alpha_86x30.c \
../Core/generated/images/_QS_alpha_86x42.c \
../Core/generated/images/_motor_alpha_40x40.c \
../Core/generated/images/_sensor_alpha_40x40.c 

OBJS += \
./Core/generated/images/_1_alpha_40x40.o \
./Core/generated/images/_2_alpha_40x40.o \
./Core/generated/images/_3_alpha_40x40.o \
./Core/generated/images/_GOP_TestCenter_LeftNav_Icon_alpha_40x40.o \
./Core/generated/images/_QS_alpha_219x92.o \
./Core/generated/images/_QS_alpha_307x91.o \
./Core/generated/images/_QS_alpha_86x30.o \
./Core/generated/images/_QS_alpha_86x42.o \
./Core/generated/images/_motor_alpha_40x40.o \
./Core/generated/images/_sensor_alpha_40x40.o 

C_DEPS += \
./Core/generated/images/_1_alpha_40x40.d \
./Core/generated/images/_2_alpha_40x40.d \
./Core/generated/images/_3_alpha_40x40.d \
./Core/generated/images/_GOP_TestCenter_LeftNav_Icon_alpha_40x40.d \
./Core/generated/images/_QS_alpha_219x92.d \
./Core/generated/images/_QS_alpha_307x91.d \
./Core/generated/images/_QS_alpha_86x30.d \
./Core/generated/images/_QS_alpha_86x42.d \
./Core/generated/images/_motor_alpha_40x40.d \
./Core/generated/images/_sensor_alpha_40x40.d 


# Each subdirectory must supply rules for building sources it contributes
Core/generated/images/%.o Core/generated/images/%.su Core/generated/images/%.cyclo: ../Core/generated/images/%.c Core/generated/images/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-generated-2f-images

clean-Core-2f-generated-2f-images:
	-$(RM) ./Core/generated/images/_1_alpha_40x40.cyclo ./Core/generated/images/_1_alpha_40x40.d ./Core/generated/images/_1_alpha_40x40.o ./Core/generated/images/_1_alpha_40x40.su ./Core/generated/images/_2_alpha_40x40.cyclo ./Core/generated/images/_2_alpha_40x40.d ./Core/generated/images/_2_alpha_40x40.o ./Core/generated/images/_2_alpha_40x40.su ./Core/generated/images/_3_alpha_40x40.cyclo ./Core/generated/images/_3_alpha_40x40.d ./Core/generated/images/_3_alpha_40x40.o ./Core/generated/images/_3_alpha_40x40.su ./Core/generated/images/_GOP_TestCenter_LeftNav_Icon_alpha_40x40.cyclo ./Core/generated/images/_GOP_TestCenter_LeftNav_Icon_alpha_40x40.d ./Core/generated/images/_GOP_TestCenter_LeftNav_Icon_alpha_40x40.o ./Core/generated/images/_GOP_TestCenter_LeftNav_Icon_alpha_40x40.su ./Core/generated/images/_QS_alpha_219x92.cyclo ./Core/generated/images/_QS_alpha_219x92.d ./Core/generated/images/_QS_alpha_219x92.o ./Core/generated/images/_QS_alpha_219x92.su ./Core/generated/images/_QS_alpha_307x91.cyclo ./Core/generated/images/_QS_alpha_307x91.d ./Core/generated/images/_QS_alpha_307x91.o ./Core/generated/images/_QS_alpha_307x91.su ./Core/generated/images/_QS_alpha_86x30.cyclo ./Core/generated/images/_QS_alpha_86x30.d ./Core/generated/images/_QS_alpha_86x30.o ./Core/generated/images/_QS_alpha_86x30.su ./Core/generated/images/_QS_alpha_86x42.cyclo ./Core/generated/images/_QS_alpha_86x42.d ./Core/generated/images/_QS_alpha_86x42.o ./Core/generated/images/_QS_alpha_86x42.su ./Core/generated/images/_motor_alpha_40x40.cyclo ./Core/generated/images/_motor_alpha_40x40.d ./Core/generated/images/_motor_alpha_40x40.o ./Core/generated/images/_motor_alpha_40x40.su ./Core/generated/images/_sensor_alpha_40x40.cyclo ./Core/generated/images/_sensor_alpha_40x40.d ./Core/generated/images/_sensor_alpha_40x40.o ./Core/generated/images/_sensor_alpha_40x40.su

.PHONY: clean-Core-2f-generated-2f-images

