################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include Src/LAB/LAB4/subdir.mk
-include Src/LAB/LAB3/subdir.mk
-include Src/LAB/LAB2/subdir.mk
-include Src/LAB/LAB1/subdir.mk
-include Src/Audio/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Lab_IT.elf

# Tool invocations
Lab_IT.elf: $(OBJS) $(USER_OBJS) ../STM32F769NIHx_FLASH.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -L"/Users/elders/STM32Cube/Repository/STM32Cube_FW_F7_V1.12.0/Drivers/CMSIS/Lib/GCC" -specs=nosys.specs -specs=nano.specs -T"../STM32F769NIHx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "Lab_IT.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Lab_IT.elf" "Lab_IT.bin"
	arm-none-eabi-size "Lab_IT.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
