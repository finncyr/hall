################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LabCode.c \
../Src/main.c \
../Src/reverb_intr.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_it.c \
../Src/system_stm32f7xx.c 

OBJS += \
./Src/LabCode.o \
./Src/main.o \
./Src/reverb_intr.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_it.o \
./Src/system_stm32f7xx.o 

C_DEPS += \
./Src/LabCode.d \
./Src/main.d \
./Src/reverb_intr.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_it.d \
./Src/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F769xx -I"C:/Sciebo/THK/SMMD/Projekt/hall/Inc" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Drivers/CMSIS/Include" -I"C:/Sciebo/THK/SMMD/Projekt/hall/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


