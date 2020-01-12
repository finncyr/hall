################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LAB/Module_3/dimpulse_intr.c \
../Src/LAB/Module_3/loop_buf_intr.c \
../Src/LAB/Module_3/loop_intr.c \
../Src/LAB/Module_3/prbs_intr.c \
../Src/LAB/Module_3/sine_intr.c \
../Src/LAB/Module_3/sine_lut_buf_intr.c \
../Src/LAB/Module_3/sine_lut_intr.c \
../Src/LAB/Module_3/square_intr.c \
../Src/LAB/Module_3/sysid_CMSIS_intr.c 

OBJS += \
./Src/LAB/Module_3/dimpulse_intr.o \
./Src/LAB/Module_3/loop_buf_intr.o \
./Src/LAB/Module_3/loop_intr.o \
./Src/LAB/Module_3/prbs_intr.o \
./Src/LAB/Module_3/sine_intr.o \
./Src/LAB/Module_3/sine_lut_buf_intr.o \
./Src/LAB/Module_3/sine_lut_intr.o \
./Src/LAB/Module_3/square_intr.o \
./Src/LAB/Module_3/sysid_CMSIS_intr.o 

C_DEPS += \
./Src/LAB/Module_3/dimpulse_intr.d \
./Src/LAB/Module_3/loop_buf_intr.d \
./Src/LAB/Module_3/loop_intr.d \
./Src/LAB/Module_3/prbs_intr.d \
./Src/LAB/Module_3/sine_intr.d \
./Src/LAB/Module_3/sine_lut_buf_intr.d \
./Src/LAB/Module_3/sine_lut_intr.d \
./Src/LAB/Module_3/square_intr.d \
./Src/LAB/Module_3/sysid_CMSIS_intr.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LAB/Module_3/%.o: ../Src/LAB/Module_3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F769xx -I"/Users/elders/TH-Koeln/Eclipse/Lab_IT/Inc" -I"/Users/elders/TH-Koeln/Eclipse/Lab_IT/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/elders/TH-Koeln/Eclipse/Lab_IT/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/elders/TH-Koeln/Eclipse/Lab_IT/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/elders/TH-Koeln/Eclipse/Lab_IT/Drivers/CMSIS/Include" -I"/Users/elders/TH-Koeln/Eclipse/Lab_IT/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


