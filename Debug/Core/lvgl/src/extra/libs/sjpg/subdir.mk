################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/extra/libs/sjpg/lv_sjpg.c \
../Core/lvgl/src/extra/libs/sjpg/tjpgd.c 

OBJS += \
./Core/lvgl/src/extra/libs/sjpg/lv_sjpg.o \
./Core/lvgl/src/extra/libs/sjpg/tjpgd.o 

C_DEPS += \
./Core/lvgl/src/extra/libs/sjpg/lv_sjpg.d \
./Core/lvgl/src/extra/libs/sjpg/tjpgd.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/extra/libs/sjpg/%.o Core/lvgl/src/extra/libs/sjpg/%.su Core/lvgl/src/extra/libs/sjpg/%.cyclo: ../Core/lvgl/src/extra/libs/sjpg/%.c Core/lvgl/src/extra/libs/sjpg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-extra-2f-libs-2f-sjpg

clean-Core-2f-lvgl-2f-src-2f-extra-2f-libs-2f-sjpg:
	-$(RM) ./Core/lvgl/src/extra/libs/sjpg/lv_sjpg.cyclo ./Core/lvgl/src/extra/libs/sjpg/lv_sjpg.d ./Core/lvgl/src/extra/libs/sjpg/lv_sjpg.o ./Core/lvgl/src/extra/libs/sjpg/lv_sjpg.su ./Core/lvgl/src/extra/libs/sjpg/tjpgd.cyclo ./Core/lvgl/src/extra/libs/sjpg/tjpgd.d ./Core/lvgl/src/extra/libs/sjpg/tjpgd.o ./Core/lvgl/src/extra/libs/sjpg/tjpgd.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-extra-2f-libs-2f-sjpg

