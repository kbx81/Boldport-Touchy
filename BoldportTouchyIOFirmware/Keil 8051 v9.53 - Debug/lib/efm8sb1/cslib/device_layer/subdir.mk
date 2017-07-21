################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/efm8sb1/cslib/device_layer/hardware_config.c \
../lib/efm8sb1/cslib/device_layer/hardware_routines.c \
../lib/efm8sb1/cslib/device_layer/low_power_config.c 

OBJS += \
./lib/efm8sb1/cslib/device_layer/hardware_config.OBJ \
./lib/efm8sb1/cslib/device_layer/hardware_routines.OBJ \
./lib/efm8sb1/cslib/device_layer/low_power_config.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/efm8sb1/cslib/device_layer/%.OBJ: ../lib/efm8sb1/cslib/device_layer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/efm8sb1/cslib/device_layer/hardware_config.OBJ: C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_hwconfig.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/lib/efm8sb1/cslib/device_layer/hardware_routines.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h

lib/efm8sb1/cslib/device_layer/hardware_routines.OBJ: C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Lib/efm8_capsense/cslib.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/lib/efm8sb1/cslib/device_layer/hardware_routines.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_hwconfig.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h

lib/efm8sb1/cslib/device_layer/low_power_config.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Lib/efm8_capsense/cslib.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_config.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/lib/efm8sb1/cslib/device_layer/low_power_hardware.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/lib/efm8sb1/cslib/device_layer/low_power_config.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_hwconfig.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h


