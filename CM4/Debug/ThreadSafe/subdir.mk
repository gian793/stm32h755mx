################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/MyFolder/Local_CNT/Projects/TestPrjH755mx/ThreadSafe/newlib_lock_glue.c 

OBJS += \
./ThreadSafe/newlib_lock_glue.o 

C_DEPS += \
./ThreadSafe/newlib_lock_glue.d 


# Each subdirectory must supply rules for building sources it contributes
ThreadSafe/newlib_lock_glue.o: C:/MyFolder/Local_CNT/Projects/TestPrjH755mx/ThreadSafe/newlib_lock_glue.c ThreadSafe/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H755xx -DDEBUG -D__NEWLIB__ -D_RETARGETABLE_LOCKING -DSTM32_THREAD_SAFE_STRATEGY=2 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../ThreadSafe -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThreadSafe

clean-ThreadSafe:
	-$(RM) ./ThreadSafe/newlib_lock_glue.cyclo ./ThreadSafe/newlib_lock_glue.d ./ThreadSafe/newlib_lock_glue.o ./ThreadSafe/newlib_lock_glue.su

.PHONY: clean-ThreadSafe

