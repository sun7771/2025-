################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32U5xx_HAL_Driver/Src/subdir.mk
-include Core/lvgl/src/widgets/subdir.mk
-include Core/lvgl/src/misc/subdir.mk
-include Core/lvgl/src/hal/subdir.mk
-include Core/lvgl/src/font/subdir.mk
-include Core/lvgl/src/extra/widgets/win/subdir.mk
-include Core/lvgl/src/extra/widgets/tileview/subdir.mk
-include Core/lvgl/src/extra/widgets/tabview/subdir.mk
-include Core/lvgl/src/extra/widgets/spinner/subdir.mk
-include Core/lvgl/src/extra/widgets/spinbox/subdir.mk
-include Core/lvgl/src/extra/widgets/span/subdir.mk
-include Core/lvgl/src/extra/widgets/msgbox/subdir.mk
-include Core/lvgl/src/extra/widgets/meter/subdir.mk
-include Core/lvgl/src/extra/widgets/menu/subdir.mk
-include Core/lvgl/src/extra/widgets/list/subdir.mk
-include Core/lvgl/src/extra/widgets/led/subdir.mk
-include Core/lvgl/src/extra/widgets/keyboard/subdir.mk
-include Core/lvgl/src/extra/widgets/imgbtn/subdir.mk
-include Core/lvgl/src/extra/widgets/colorwheel/subdir.mk
-include Core/lvgl/src/extra/widgets/chart/subdir.mk
-include Core/lvgl/src/extra/widgets/calendar/subdir.mk
-include Core/lvgl/src/extra/widgets/animimg/subdir.mk
-include Core/lvgl/src/extra/themes/mono/subdir.mk
-include Core/lvgl/src/extra/themes/default/subdir.mk
-include Core/lvgl/src/extra/themes/basic/subdir.mk
-include Core/lvgl/src/extra/others/snapshot/subdir.mk
-include Core/lvgl/src/extra/others/msg/subdir.mk
-include Core/lvgl/src/extra/others/monkey/subdir.mk
-include Core/lvgl/src/extra/others/imgfont/subdir.mk
-include Core/lvgl/src/extra/others/ime/subdir.mk
-include Core/lvgl/src/extra/others/gridnav/subdir.mk
-include Core/lvgl/src/extra/others/fragment/subdir.mk
-include Core/lvgl/src/extra/libs/sjpg/subdir.mk
-include Core/lvgl/src/extra/libs/rlottie/subdir.mk
-include Core/lvgl/src/extra/libs/qrcode/subdir.mk
-include Core/lvgl/src/extra/libs/png/subdir.mk
-include Core/lvgl/src/extra/libs/gif/subdir.mk
-include Core/lvgl/src/extra/libs/fsdrv/subdir.mk
-include Core/lvgl/src/extra/libs/freetype/subdir.mk
-include Core/lvgl/src/extra/libs/ffmpeg/subdir.mk
-include Core/lvgl/src/extra/libs/bmp/subdir.mk
-include Core/lvgl/src/extra/layouts/grid/subdir.mk
-include Core/lvgl/src/extra/layouts/flex/subdir.mk
-include Core/lvgl/src/extra/subdir.mk
-include Core/lvgl/src/draw/swm341_dma2d/subdir.mk
-include Core/lvgl/src/draw/sw/subdir.mk
-include Core/lvgl/src/draw/stm32_dma2d/subdir.mk
-include Core/lvgl/src/draw/sdl/subdir.mk
-include Core/lvgl/src/draw/nxp/vglite/subdir.mk
-include Core/lvgl/src/draw/nxp/pxp/subdir.mk
-include Core/lvgl/src/draw/nxp/subdir.mk
-include Core/lvgl/src/draw/arm2d/subdir.mk
-include Core/lvgl/src/draw/subdir.mk
-include Core/lvgl/src/core/subdir.mk
-include Core/lvgl/example/porting/subdir.mk
-include Core/generated/images/subdir.mk
-include Core/generated/guider_fonts/subdir.mk
-include Core/generated/subdir.mk
-include Core/custom/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/APP/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := AIT1
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
AIT1.elf \

MAP_FILES += \
AIT1.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
AIT1.list \


# All Target
all: main-build

# Main-build Target
main-build: AIT1.elf secondary-outputs

# Tool invocations
AIT1.elf AIT1.map: $(OBJS) $(USER_OBJS) E:\My_Project\qian_ru_shi_she_ji_da_sai\V3\STM32U575VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "AIT1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m33 -T"E:\My_Project\qian_ru_shi_she_ji_da_sai\V3\STM32U575VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="AIT1.map" -Wl,--gc-sections -static -L"E:\My_Project\qian_ru_shi_she_ji_da_sai\V3\Core\APP" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

AIT1.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "AIT1.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) AIT1.elf AIT1.list AIT1.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
