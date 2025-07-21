################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/widgets/lv_arc.c \
../Core/lvgl/src/widgets/lv_bar.c \
../Core/lvgl/src/widgets/lv_btn.c \
../Core/lvgl/src/widgets/lv_btnmatrix.c \
../Core/lvgl/src/widgets/lv_canvas.c \
../Core/lvgl/src/widgets/lv_checkbox.c \
../Core/lvgl/src/widgets/lv_dropdown.c \
../Core/lvgl/src/widgets/lv_img.c \
../Core/lvgl/src/widgets/lv_label.c \
../Core/lvgl/src/widgets/lv_line.c \
../Core/lvgl/src/widgets/lv_objx_templ.c \
../Core/lvgl/src/widgets/lv_roller.c \
../Core/lvgl/src/widgets/lv_slider.c \
../Core/lvgl/src/widgets/lv_switch.c \
../Core/lvgl/src/widgets/lv_table.c \
../Core/lvgl/src/widgets/lv_textarea.c 

OBJS += \
./Core/lvgl/src/widgets/lv_arc.o \
./Core/lvgl/src/widgets/lv_bar.o \
./Core/lvgl/src/widgets/lv_btn.o \
./Core/lvgl/src/widgets/lv_btnmatrix.o \
./Core/lvgl/src/widgets/lv_canvas.o \
./Core/lvgl/src/widgets/lv_checkbox.o \
./Core/lvgl/src/widgets/lv_dropdown.o \
./Core/lvgl/src/widgets/lv_img.o \
./Core/lvgl/src/widgets/lv_label.o \
./Core/lvgl/src/widgets/lv_line.o \
./Core/lvgl/src/widgets/lv_objx_templ.o \
./Core/lvgl/src/widgets/lv_roller.o \
./Core/lvgl/src/widgets/lv_slider.o \
./Core/lvgl/src/widgets/lv_switch.o \
./Core/lvgl/src/widgets/lv_table.o \
./Core/lvgl/src/widgets/lv_textarea.o 

C_DEPS += \
./Core/lvgl/src/widgets/lv_arc.d \
./Core/lvgl/src/widgets/lv_bar.d \
./Core/lvgl/src/widgets/lv_btn.d \
./Core/lvgl/src/widgets/lv_btnmatrix.d \
./Core/lvgl/src/widgets/lv_canvas.d \
./Core/lvgl/src/widgets/lv_checkbox.d \
./Core/lvgl/src/widgets/lv_dropdown.d \
./Core/lvgl/src/widgets/lv_img.d \
./Core/lvgl/src/widgets/lv_label.d \
./Core/lvgl/src/widgets/lv_line.d \
./Core/lvgl/src/widgets/lv_objx_templ.d \
./Core/lvgl/src/widgets/lv_roller.d \
./Core/lvgl/src/widgets/lv_slider.d \
./Core/lvgl/src/widgets/lv_switch.d \
./Core/lvgl/src/widgets/lv_table.d \
./Core/lvgl/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/widgets/%.o Core/lvgl/src/widgets/%.su Core/lvgl/src/widgets/%.cyclo: ../Core/lvgl/src/widgets/%.c Core/lvgl/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/APP" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example/porting" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/example" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/core" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/draw" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/extra" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/font" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/hal" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/misc" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/lvgl/src/widgets" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/custom" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_customer_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/guider_fonts" -I"E:/My_Project/qian_ru_shi_she_ji_da_sai/V3/Core/generated/images" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-widgets

clean-Core-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./Core/lvgl/src/widgets/lv_arc.cyclo ./Core/lvgl/src/widgets/lv_arc.d ./Core/lvgl/src/widgets/lv_arc.o ./Core/lvgl/src/widgets/lv_arc.su ./Core/lvgl/src/widgets/lv_bar.cyclo ./Core/lvgl/src/widgets/lv_bar.d ./Core/lvgl/src/widgets/lv_bar.o ./Core/lvgl/src/widgets/lv_bar.su ./Core/lvgl/src/widgets/lv_btn.cyclo ./Core/lvgl/src/widgets/lv_btn.d ./Core/lvgl/src/widgets/lv_btn.o ./Core/lvgl/src/widgets/lv_btn.su ./Core/lvgl/src/widgets/lv_btnmatrix.cyclo ./Core/lvgl/src/widgets/lv_btnmatrix.d ./Core/lvgl/src/widgets/lv_btnmatrix.o ./Core/lvgl/src/widgets/lv_btnmatrix.su ./Core/lvgl/src/widgets/lv_canvas.cyclo ./Core/lvgl/src/widgets/lv_canvas.d ./Core/lvgl/src/widgets/lv_canvas.o ./Core/lvgl/src/widgets/lv_canvas.su ./Core/lvgl/src/widgets/lv_checkbox.cyclo ./Core/lvgl/src/widgets/lv_checkbox.d ./Core/lvgl/src/widgets/lv_checkbox.o ./Core/lvgl/src/widgets/lv_checkbox.su ./Core/lvgl/src/widgets/lv_dropdown.cyclo ./Core/lvgl/src/widgets/lv_dropdown.d ./Core/lvgl/src/widgets/lv_dropdown.o ./Core/lvgl/src/widgets/lv_dropdown.su ./Core/lvgl/src/widgets/lv_img.cyclo ./Core/lvgl/src/widgets/lv_img.d ./Core/lvgl/src/widgets/lv_img.o ./Core/lvgl/src/widgets/lv_img.su ./Core/lvgl/src/widgets/lv_label.cyclo ./Core/lvgl/src/widgets/lv_label.d ./Core/lvgl/src/widgets/lv_label.o ./Core/lvgl/src/widgets/lv_label.su ./Core/lvgl/src/widgets/lv_line.cyclo ./Core/lvgl/src/widgets/lv_line.d ./Core/lvgl/src/widgets/lv_line.o ./Core/lvgl/src/widgets/lv_line.su ./Core/lvgl/src/widgets/lv_objx_templ.cyclo ./Core/lvgl/src/widgets/lv_objx_templ.d ./Core/lvgl/src/widgets/lv_objx_templ.o ./Core/lvgl/src/widgets/lv_objx_templ.su ./Core/lvgl/src/widgets/lv_roller.cyclo ./Core/lvgl/src/widgets/lv_roller.d ./Core/lvgl/src/widgets/lv_roller.o ./Core/lvgl/src/widgets/lv_roller.su ./Core/lvgl/src/widgets/lv_slider.cyclo ./Core/lvgl/src/widgets/lv_slider.d ./Core/lvgl/src/widgets/lv_slider.o ./Core/lvgl/src/widgets/lv_slider.su ./Core/lvgl/src/widgets/lv_switch.cyclo ./Core/lvgl/src/widgets/lv_switch.d ./Core/lvgl/src/widgets/lv_switch.o ./Core/lvgl/src/widgets/lv_switch.su ./Core/lvgl/src/widgets/lv_table.cyclo ./Core/lvgl/src/widgets/lv_table.d ./Core/lvgl/src/widgets/lv_table.o ./Core/lvgl/src/widgets/lv_table.su ./Core/lvgl/src/widgets/lv_textarea.cyclo ./Core/lvgl/src/widgets/lv_textarea.d ./Core/lvgl/src/widgets/lv_textarea.o ./Core/lvgl/src/widgets/lv_textarea.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-widgets

