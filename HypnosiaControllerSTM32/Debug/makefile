################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
HypnosiaControllerSTM32.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
HypnosiaControllerSTM32.list \

OBJCOPY_BIN += \
HypnosiaControllerSTM32.bin \


# All Target
all: HypnosiaControllerSTM32.elf secondary-outputs

# Tool invocations
HypnosiaControllerSTM32.elf: $(OBJS) $(USER_OBJS) C:\Users\gerac\Desktop\HES-SO_3\BACHELOR_THESIS\HypnosiaControllerGIT\HypnosiaControllerSTM32\STM32F072V8TX_FLASH.ld
	arm-none-eabi-gcc -o "HypnosiaControllerSTM32.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"C:\Users\gerac\Desktop\HES-SO_3\BACHELOR_THESIS\HypnosiaControllerGIT\HypnosiaControllerSTM32\STM32F072V8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="HypnosiaControllerSTM32.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

HypnosiaControllerSTM32.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "HypnosiaControllerSTM32.list"
	@echo 'Finished building: $@'
	@echo ' '

HypnosiaControllerSTM32.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "HypnosiaControllerSTM32.bin"
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
