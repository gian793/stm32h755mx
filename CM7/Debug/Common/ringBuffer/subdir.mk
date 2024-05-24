################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/giancarlo/Documents/g793Projects/stm32h755mx/Common/ringBuffer/ringBuffer.cpp 

OBJS += \
./Common/ringBuffer/ringBuffer.o 

CPP_DEPS += \
./Common/ringBuffer/ringBuffer.d 


# Each subdirectory must supply rules for building sources it contributes
Common/ringBuffer/ringBuffer.o: /home/giancarlo/Documents/g793Projects/stm32h755mx/Common/ringBuffer/ringBuffer.cpp Common/ringBuffer/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++20 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H755xx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I../../ThreadSafe -I../../Common/ringBuffer -I../../Common/mxLog -I../../Common/utils -I../../Common/cmdCtrl -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I"/home/giancarlo/Documents/g793Projects/stm32h755mx/CM7/Core" -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-ringBuffer

clean-Common-2f-ringBuffer:
	-$(RM) ./Common/ringBuffer/ringBuffer.cyclo ./Common/ringBuffer/ringBuffer.d ./Common/ringBuffer/ringBuffer.o ./Common/ringBuffer/ringBuffer.su

.PHONY: clean-Common-2f-ringBuffer

