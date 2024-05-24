################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/giancarlo/Documents/g793Projects/stm32h755mx/Common/utils/utils.cpp 

OBJS += \
./Common/utils/utils.o 

CPP_DEPS += \
./Common/utils/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Common/utils/utils.o: /home/giancarlo/Documents/g793Projects/stm32h755mx/Common/utils/utils.cpp Common/utils/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++20 -g -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H755xx -DSTM32_THREAD_SAFE_STRATEGY=2 -c -I../Core/Inc -I../../ThreadSafe -I../../Common/ringBuffer -I../../Common/mxLog -I../../Common/utils -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -Wextra -pedantic-errors -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wconversion -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-utils

clean-Common-2f-utils:
	-$(RM) ./Common/utils/utils.cyclo ./Common/utils/utils.d ./Common/utils/utils.o ./Common/utils/utils.su

.PHONY: clean-Common-2f-utils

