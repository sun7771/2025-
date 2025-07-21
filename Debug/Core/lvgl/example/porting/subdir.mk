################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/example/porting/lv_port_disp_template.c \
../Core/lvgl/example/porting/lv_port_fs_template.c \
../Core/lvgl/example/porting/lv_port_indev_template.c 

OBJS += \
./Core/lvgl/example/porting/lv_port_disp_template.o \
./Core/lvgl/example/porting/lv_port_fs_template.o \
./Core/lvgl/example/porting/lv_port_indev_template.o 

C_DEPS += \
./Core/lvgl/example/porting/lv_port_disp_template.d \
./Core/lvgl/example/porting/lv_port_fs_template.d \
./Core/lvgl/example/porting/lv_port_indev_template.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/example/porting/%.o Core/lvgl/example/porting/%.su Core/lvgl/example/porting/%.cyclo: ../Core/lvgl/example/porting/%.c Core/lvgl/example/porting/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-example-2f-porting

clean-Core-2f-lvgl-2f-example-2f-porting:
	-$(RM) ./Core/lvgl/example/porting/lv_port_disp_template.cyclo ./Core/lvgl/example/porting/lv_port_disp_template.d ./Core/lvgl/example/porting/lv_port_disp_template.o ./Core/lvgl/example/porting/lv_port_disp_template.su ./Core/lvgl/example/porting/lv_port_fs_template.cyclo ./Core/lvgl/example/porting/lv_port_fs_template.d ./Core/lvgl/example/porting/lv_port_fs_template.o ./Core/lvgl/example/porting/lv_port_fs_template.su ./Core/lvgl/example/porting/lv_port_indev_template.cyclo ./Core/lvgl/example/porting/lv_port_indev_template.d ./Core/lvgl/example/porting/lv_port_indev_template.o ./Core/lvgl/example/porting/lv_port_indev_template.su

.PHONY: clean-Core-2f-lvgl-2f-example-2f-porting

