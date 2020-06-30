################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32f0xx_hal_msp.c \
../Core/Src/stm32f0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f0xx.c 

CPP_SRCS += \
../Core/Src/isrs.cpp 

OBJS += \
./Core/Src/isrs.o \
./Core/Src/main.o \
./Core/Src/stm32f0xx_hal_msp.o \
./Core/Src/stm32f0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f0xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32f0xx_hal_msp.d \
./Core/Src/stm32f0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f0xx.d 

CPP_DEPS += \
./Core/Src/isrs.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/isrs.o: ../Core/Src/isrs.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Core/Src/isrs.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/stm32f0xx_hal_msp.o: ../Core/Src/stm32f0xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f0xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/stm32f0xx_it.o: ../Core/Src/stm32f0xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f0xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/syscalls.o: ../Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/sysmem.o: ../Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/system_stm32f0xx.o: ../Core/Src/system_stm32f0xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32f0xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

