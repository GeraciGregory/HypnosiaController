################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/src/xf/port/default-idf/eventqueue-default.cpp \
C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/src/xf/port/default-idf/mutex-default.cpp 

OBJS += \
./xf/port/default-idf/eventqueue-default.o \
./xf/port/default-idf/mutex-default.o 

CPP_DEPS += \
./xf/port/default-idf/eventqueue-default.d \
./xf/port/default-idf/mutex-default.d 


# Each subdirectory must supply rules for building sources it contributes
xf/port/default-idf/eventqueue-default.o: C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/src/xf/port/default-idf/eventqueue-default.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"xf/port/default-idf/eventqueue-default.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
xf/port/default-idf/mutex-default.o: C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/src/xf/port/default-idf/mutex-default.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F072xB -DDEBUG -c -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/config" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/mcu" -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/port/default-idf" -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src/xf/include" -I"C:/Users/gerac/Desktop/HES-SO_3/BACHELOR_THESIS/HypnosiaControllerGIT/STM32/STM32HypnosiaController/../src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"xf/port/default-idf/mutex-default.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

