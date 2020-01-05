################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.c \
../Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_lcd.c \
../Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sdram.c \
../Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_ts.c 

OBJS += \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.o \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_lcd.o \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sdram.o \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_ts.o 

C_DEPS += \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.d \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_lcd.d \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sdram.d \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F769I-Discovery/%.o: ../Drivers/BSP/STM32F769I-Discovery/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DARM_MATH_CM7 '-D__FPU_PRESENT=1' '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -I"/Users/elders/Eclipse/DMA_Display/Inc" -I"/Users/elders/Eclipse/DMA_Display/Drivers/BSP" -I"/Users/elders/Eclipse/DMA_Display/Drivers/STM32F7xx_HAL_Driver/Inc" -I"/Users/elders/Eclipse/DMA_Display/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"/Users/elders/Eclipse/DMA_Display/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"/Users/elders/Eclipse/DMA_Display/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/DMA_Display/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/DMA_Display/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/DMA_Display/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/DMA_Display/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/DMA_Display/Drivers/CMSIS/Include" -I"/Users/elders/Eclipse/DMA_Display/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


