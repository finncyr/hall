################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LAB/LAB4/iir_intr.c \
../Src/LAB/LAB4/iir_intr_solution.c \
../Src/LAB/LAB4/iirsos_intr.c \
../Src/LAB/LAB4/iirsos_intr_solution.c \
../Src/LAB/LAB4/loop_intr.c 

OBJS += \
./Src/LAB/LAB4/iir_intr.o \
./Src/LAB/LAB4/iir_intr_solution.o \
./Src/LAB/LAB4/iirsos_intr.o \
./Src/LAB/LAB4/iirsos_intr_solution.o \
./Src/LAB/LAB4/loop_intr.o 

C_DEPS += \
./Src/LAB/LAB4/iir_intr.d \
./Src/LAB/LAB4/iir_intr_solution.d \
./Src/LAB/LAB4/iirsos_intr.d \
./Src/LAB/LAB4/iirsos_intr_solution.d \
./Src/LAB/LAB4/loop_intr.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LAB/LAB4/%.o: ../Src/LAB/LAB4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F769xx -I"/Users/elders/Eclipse/Lab_IT/Inc" -I"/Users/elders/Eclipse/Lab_IT/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/elders/Eclipse/Lab_IT/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/elders/Eclipse/Lab_IT/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/elders/Eclipse/Lab_IT/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/Lab_IT/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


