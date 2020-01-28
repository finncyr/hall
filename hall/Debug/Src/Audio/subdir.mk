################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Audio/audio.c \
../Src/Audio/wm8994_config.c 

OBJS += \
./Src/Audio/audio.o \
./Src/Audio/wm8994_config.o 

C_DEPS += \
./Src/Audio/audio.d \
./Src/Audio/wm8994_config.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Audio/%.o: ../Src/Audio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F769xx -I"/Users/elders/Eclipse/Lab_IT/Inc" -I"/Users/elders/Eclipse/Lab_IT/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/elders/Eclipse/Lab_IT/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/elders/Eclipse/Lab_IT/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/elders/Eclipse/Lab_IT/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/Lab_IT/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


