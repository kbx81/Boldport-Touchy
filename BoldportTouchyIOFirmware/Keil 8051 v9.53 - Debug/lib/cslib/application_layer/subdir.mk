################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/cslib/application_layer/cslib_config.c 

OBJS += \
./lib/cslib/application_layer/cslib_config.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/cslib/application_layer/%.OBJ: ../lib/cslib/application_layer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/cslib/application_layer/cslib_config.OBJ: C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Lib/efm8_capsense/cslib.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h


