################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/giancarlo/Documents/g793Projects/stm32h755mx/Common/unitTest/doubles/stm32h7xx_hal_uart.c 

C_DEPS += \
./Common/unitTest/doubles/stm32h7xx_hal_uart.d 

OBJS += \
./Common/unitTest/doubles/stm32h7xx_hal_uart.o 


# Each subdirectory must supply rules for building sources it contributes
Common/unitTest/doubles/stm32h7xx_hal_uart.o: /home/giancarlo/Documents/g793Projects/stm32h755mx/Common/unitTest/doubles/stm32h7xx_hal_uart.c Common/unitTest/doubles/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H755xx -DDEBUG -D__NEWLIB__ -D_RETARGETABLE_LOCKING -DSTM32_THREAD_SAFE_STRATEGY=2 -c -I../Core/Inc -I../../ThreadSafe -I../Core/ThreadSafe -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-unitTest-2f-doubles

clean-Common-2f-unitTest-2f-doubles:
	-$(RM) ./Common/unitTest/doubles/stm32h7xx_hal_uart.cyclo ./Common/unitTest/doubles/stm32h7xx_hal_uart.d ./Common/unitTest/doubles/stm32h7xx_hal_uart.o ./Common/unitTest/doubles/stm32h7xx_hal_uart.su

.PHONY: clean-Common-2f-unitTest-2f-doubles

