################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LAB/LAB1/delay_intr.c \
../Src/LAB/LAB1/echo_intr.c \
../Src/LAB/LAB1/loop_intr.c \
../Src/LAB/LAB1/sine_lut_buf_intr.c \
../Src/LAB/LAB1/sine_lut_intr.c 

OBJS += \
./Src/LAB/LAB1/delay_intr.o \
./Src/LAB/LAB1/echo_intr.o \
./Src/LAB/LAB1/loop_intr.o \
./Src/LAB/LAB1/sine_lut_buf_intr.o \
./Src/LAB/LAB1/sine_lut_intr.o 

C_DEPS += \
./Src/LAB/LAB1/delay_intr.d \
./Src/LAB/LAB1/echo_intr.d \
./Src/LAB/LAB1/loop_intr.d \
./Src/LAB/LAB1/sine_lut_buf_intr.d \
./Src/LAB/LAB1/sine_lut_intr.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LAB/LAB1/%.o: ../Src/LAB/LAB1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F769xx -I"/Users/elders/Eclipse/Lab_IT/Inc" -I"/Users/elders/Eclipse/Lab_IT/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/elders/Eclipse/Lab_IT/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/elders/Eclipse/Lab_IT/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/elders/Eclipse/Lab_IT/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/Lab_IT/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


