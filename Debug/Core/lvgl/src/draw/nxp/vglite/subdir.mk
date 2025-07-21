################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.c \
../Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.c \
../Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.c \
../Core/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.c 

OBJS += \
./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o \
./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o \
./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o \
./Core/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.o 

C_DEPS += \
./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d \
./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d \
./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d \
./Core/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/draw/nxp/vglite/%.o Core/lvgl/src/draw/nxp/vglite/%.su Core/lvgl/src/draw/nxp/vglite/%.cyclo: ../Core/lvgl/src/draw/nxp/vglite/%.c Core/lvgl/src/draw/nxp/vglite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

clean-Core-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite:
	-$(RM) ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.cyclo ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.su ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.cyclo ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.su ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.cyclo ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o ./Core/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.su ./Core/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.cyclo ./Core/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.d ./Core/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.o ./Core/lvgl/src/draw/nxp/vglite/lv_gpu_nxp_vglite.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

