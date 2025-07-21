################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_12.c \
../Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_16.c \
../Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_41.c 

OBJS += \
./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_12.o \
./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_16.o \
./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_41.o 

C_DEPS += \
./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_12.d \
./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_16.d \
./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_41.d 


# Each subdirectory must supply rules for building sources it contributes
Core/generated/guider_fonts/%.o Core/generated/guider_fonts/%.su Core/generated/guider_fonts/%.cyclo: ../Core/generated/guider_fonts/%.c Core/generated/guider_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-generated-2f-guider_fonts

clean-Core-2f-generated-2f-guider_fonts:
	-$(RM) ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_12.cyclo ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_12.d ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_12.o ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_12.su ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_16.cyclo ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_16.d ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_16.o ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_16.su ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_41.cyclo ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_41.d ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_41.o ./Core/generated/guider_fonts/lv_font_SourceHanSansCN_Normal_41.su

.PHONY: clean-Core-2f-generated-2f-guider_fonts

