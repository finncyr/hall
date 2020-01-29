################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LAB/LAB3/average_intr.c \
../Src/LAB/LAB3/average_prbs_intr.c \
../Src/LAB/LAB3/fir_intr.c \
../Src/LAB/LAB3/fir_prbs_CMSIS_intr.c \
../Src/LAB/LAB3/fir_prbs_intr.c \
../Src/LAB/LAB3/loop_intr.c \
../Src/LAB/LAB3/sysid_CMSIS_intr.c \
../Src/LAB/LAB3/sysid_average_CMSIS_intr.c 

OBJS += \
./Src/LAB/LAB3/average_intr.o \
./Src/LAB/LAB3/average_prbs_intr.o \
./Src/LAB/LAB3/fir_intr.o \
./Src/LAB/LAB3/fir_prbs_CMSIS_intr.o \
./Src/LAB/LAB3/fir_prbs_intr.o \
./Src/LAB/LAB3/loop_intr.o \
./Src/LAB/LAB3/sysid_CMSIS_intr.o \
./Src/LAB/LAB3/sysid_average_CMSIS_intr.o 

C_DEPS += \
./Src/LAB/LAB3/average_intr.d \
./Src/LAB/LAB3/average_prbs_intr.d \
./Src/LAB/LAB3/fir_intr.d \
./Src/LAB/LAB3/fir_prbs_CMSIS_intr.d \
./Src/LAB/LAB3/fir_prbs_intr.d \
./Src/LAB/LAB3/loop_intr.d \
./Src/LAB/LAB3/sysid_CMSIS_intr.d \
./Src/LAB/LAB3/sysid_average_CMSIS_intr.d 


# Each subdirectory must supply rules for building sources it contributes
Src/LAB/LAB3/%.o: ../Src/LAB/LAB3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F769xx -I"C:/Sciebo/THK/SMMD/Projekt/hall/Inc" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Drivers/CMSIS/Include" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


