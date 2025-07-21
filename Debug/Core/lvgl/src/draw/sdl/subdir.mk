################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/draw/sdl/lv_draw_sdl.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_layer.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../Core/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./Core/lvgl/src/draw/sdl/lv_draw_sdl.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_layer.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./Core/lvgl/src/draw/sdl/lv_draw_sdl.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_layer.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./Core/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/draw/sdl/%.o Core/lvgl/src/draw/sdl/%.su Core/lvgl/src/draw/sdl/%.cyclo: ../Core/lvgl/src/draw/sdl/%.c Core/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-Core-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./Core/lvgl/src/draw/sdl/lv_draw_sdl.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_arc.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_bg.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_composite.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_img.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_label.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_layer.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_layer.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_layer.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_layer.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_line.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_mask.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_polygon.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_rect.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./Core/lvgl/src/draw/sdl/lv_draw_sdl_utils.cyclo ./Core/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./Core/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./Core/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-draw-2f-sdl

