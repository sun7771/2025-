################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/generated/events_init.c \
../Core/generated/gui_guider.c \
../Core/generated/setup_scr_screen.c \
../Core/generated/setup_scr_screen_1.c \
../Core/generated/setup_scr_screen_2.c \
../Core/generated/setup_scr_screen_3.c \
../Core/generated/widgets_init.c 

OBJS += \
./Core/generated/events_init.o \
./Core/generated/gui_guider.o \
./Core/generated/setup_scr_screen.o \
./Core/generated/setup_scr_screen_1.o \
./Core/generated/setup_scr_screen_2.o \
./Core/generated/setup_scr_screen_3.o \
./Core/generated/widgets_init.o 

C_DEPS += \
./Core/generated/events_init.d \
./Core/generated/gui_guider.d \
./Core/generated/setup_scr_screen.d \
./Core/generated/setup_scr_screen_1.d \
./Core/generated/setup_scr_screen_2.d \
./Core/generated/setup_scr_screen_3.d \
./Core/generated/widgets_init.d 


# Each subdirectory must supply rules for building sources it contributes
Core/generated/%.o Core/generated/%.su Core/generated/%.cyclo: ../Core/generated/%.c Core/generated/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-generated

clean-Core-2f-generated:
	-$(RM) ./Core/generated/events_init.cyclo ./Core/generated/events_init.d ./Core/generated/events_init.o ./Core/generated/events_init.su ./Core/generated/gui_guider.cyclo ./Core/generated/gui_guider.d ./Core/generated/gui_guider.o ./Core/generated/gui_guider.su ./Core/generated/setup_scr_screen.cyclo ./Core/generated/setup_scr_screen.d ./Core/generated/setup_scr_screen.o ./Core/generated/setup_scr_screen.su ./Core/generated/setup_scr_screen_1.cyclo ./Core/generated/setup_scr_screen_1.d ./Core/generated/setup_scr_screen_1.o ./Core/generated/setup_scr_screen_1.su ./Core/generated/setup_scr_screen_2.cyclo ./Core/generated/setup_scr_screen_2.d ./Core/generated/setup_scr_screen_2.o ./Core/generated/setup_scr_screen_2.su ./Core/generated/setup_scr_screen_3.cyclo ./Core/generated/setup_scr_screen_3.d ./Core/generated/setup_scr_screen_3.o ./Core/generated/setup_scr_screen_3.su ./Core/generated/widgets_init.cyclo ./Core/generated/widgets_init.d ./Core/generated/widgets_init.o ./Core/generated/widgets_init.su

.PHONY: clean-Core-2f-generated

