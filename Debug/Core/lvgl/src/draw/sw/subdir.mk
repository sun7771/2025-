################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/draw/sw/lv_draw_sw.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_blend.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_dither.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_img.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_layer.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_line.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_polygon.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_rect.c \
../Core/lvgl/src/draw/sw/lv_draw_sw_transform.c 

OBJS += \
./Core/lvgl/src/draw/sw/lv_draw_sw.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_blend.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_dither.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_img.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_layer.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_line.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_polygon.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_rect.o \
./Core/lvgl/src/draw/sw/lv_draw_sw_transform.o 

C_DEPS += \
./Core/lvgl/src/draw/sw/lv_draw_sw.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_blend.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_dither.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_img.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_layer.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_line.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_polygon.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_rect.d \
./Core/lvgl/src/draw/sw/lv_draw_sw_transform.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/draw/sw/%.o Core/lvgl/src/draw/sw/%.su Core/lvgl/src/draw/sw/%.cyclo: ../Core/lvgl/src/draw/sw/%.c Core/lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-draw-2f-sw

clean-Core-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./Core/lvgl/src/draw/sw/lv_draw_sw.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw.d ./Core/lvgl/src/draw/sw/lv_draw_sw.o ./Core/lvgl/src/draw/sw/lv_draw_sw.su ./Core/lvgl/src/draw/sw/lv_draw_sw_arc.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_arc.d ./Core/lvgl/src/draw/sw/lv_draw_sw_arc.o ./Core/lvgl/src/draw/sw/lv_draw_sw_arc.su ./Core/lvgl/src/draw/sw/lv_draw_sw_blend.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_blend.d ./Core/lvgl/src/draw/sw/lv_draw_sw_blend.o ./Core/lvgl/src/draw/sw/lv_draw_sw_blend.su ./Core/lvgl/src/draw/sw/lv_draw_sw_dither.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_dither.d ./Core/lvgl/src/draw/sw/lv_draw_sw_dither.o ./Core/lvgl/src/draw/sw/lv_draw_sw_dither.su ./Core/lvgl/src/draw/sw/lv_draw_sw_gradient.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./Core/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./Core/lvgl/src/draw/sw/lv_draw_sw_gradient.su ./Core/lvgl/src/draw/sw/lv_draw_sw_img.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_img.d ./Core/lvgl/src/draw/sw/lv_draw_sw_img.o ./Core/lvgl/src/draw/sw/lv_draw_sw_img.su ./Core/lvgl/src/draw/sw/lv_draw_sw_layer.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_layer.d ./Core/lvgl/src/draw/sw/lv_draw_sw_layer.o ./Core/lvgl/src/draw/sw/lv_draw_sw_layer.su ./Core/lvgl/src/draw/sw/lv_draw_sw_letter.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_letter.d ./Core/lvgl/src/draw/sw/lv_draw_sw_letter.o ./Core/lvgl/src/draw/sw/lv_draw_sw_letter.su ./Core/lvgl/src/draw/sw/lv_draw_sw_line.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_line.d ./Core/lvgl/src/draw/sw/lv_draw_sw_line.o ./Core/lvgl/src/draw/sw/lv_draw_sw_line.su ./Core/lvgl/src/draw/sw/lv_draw_sw_polygon.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_polygon.d ./Core/lvgl/src/draw/sw/lv_draw_sw_polygon.o ./Core/lvgl/src/draw/sw/lv_draw_sw_polygon.su ./Core/lvgl/src/draw/sw/lv_draw_sw_rect.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_rect.d ./Core/lvgl/src/draw/sw/lv_draw_sw_rect.o ./Core/lvgl/src/draw/sw/lv_draw_sw_rect.su ./Core/lvgl/src/draw/sw/lv_draw_sw_transform.cyclo ./Core/lvgl/src/draw/sw/lv_draw_sw_transform.d ./Core/lvgl/src/draw/sw/lv_draw_sw_transform.o ./Core/lvgl/src/draw/sw/lv_draw_sw_transform.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-draw-2f-sw

