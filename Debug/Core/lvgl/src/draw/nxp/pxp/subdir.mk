################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.c \
../Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.c \
../Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.c 

OBJS += \
./Core/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.o \
./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.o \
./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.o 

C_DEPS += \
./Core/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.d \
./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.d \
./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/draw/nxp/pxp/%.o Core/lvgl/src/draw/nxp/pxp/%.su Core/lvgl/src/draw/nxp/pxp/%.cyclo: ../Core/lvgl/src/draw/nxp/pxp/%.c Core/lvgl/src/draw/nxp/pxp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

clean-Core-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp:
	-$(RM) ./Core/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.cyclo ./Core/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.d ./Core/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.o ./Core/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.su ./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.cyclo ./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.d ./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.o ./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.su ./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.cyclo ./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.d ./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.o ./Core/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

