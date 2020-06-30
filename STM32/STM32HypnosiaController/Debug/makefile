################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xf/port/stm32cube-cmsis-freertos/subdir.mk
-include xf/port/idf-stm32cube/subdir.mk
-include xf/port/idf-qt/subdir.mk
-include xf/port/default-qt/subdir.mk
-include xf/port/default-idf/subdir.mk
-include xf/port/default-cmsis-os/subdir.mk
-include xf/port/default/subdir.mk
-include xf/port/active-qt/subdir.mk
-include xf/core/subdir.mk
-include mcu/critical/subdir.mk
-include event/subdir.mk
-include app/subdir.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32HypnosiaController.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32HypnosiaController.list \

OBJCOPY_BIN += \
STM32HypnosiaController.bin \


# All Target
all: STM32HypnosiaController.elf secondary-outputs

# Tool invocations
STM32HypnosiaController.elf: $(OBJS) $(USER_OBJS) C:\Users\gerac\Desktop\HES-SO_3\BACHELOR_THESIS\HypnosiaControllerGIT\STM32\STM32HypnosiaController\STM32F072V8TX_FLASH.ld
	arm-none-eabi-g++ -o "STM32HypnosiaController.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"C:\Users\gerac\Desktop\HES-SO_3\BACHELOR_THESIS\HypnosiaControllerGIT\STM32\STM32HypnosiaController\STM32F072V8TX_FLASH.ld" -Wl,-Map="STM32HypnosiaController.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32HypnosiaController.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32HypnosiaController.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32HypnosiaController.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32HypnosiaController.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
