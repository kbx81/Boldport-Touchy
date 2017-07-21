################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
../src/SILABS_STARTUP.A51 

C_SRCS += \
../src/InitDevice.c \
../src/Interrupts.c \
../src/circle_slider.c \
../src/main.c \
../src/tick.c \
../src/touchy.c 

OBJS += \
./src/InitDevice.OBJ \
./src/Interrupts.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/circle_slider.OBJ \
./src/main.OBJ \
./src/tick.OBJ \
./src/touchy.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Lib/efm8_capsense/cslib.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h

src/Interrupts.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/touchy.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/main.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/toolchains/keil_8051/9.53/INC/STDLIB.H C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/InitDevice.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/circle_slider.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/tick.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/circle_slider.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/circle_slider.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Lib/efm8_capsense/cslib.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/touchy.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h

src/main.OBJ: C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/main.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/touchy.h C:/SiliconLabs/SimplicityStudio/v4/developer/toolchains/keil_8051/9.53/INC/STDLIB.H C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Lib/efm8_capsense/cslib.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/InitDevice.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/circle_slider.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/tick.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h

src/tick.OBJ: C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/main.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v4/developer/toolchains/keil_8051/9.53/INC/STDLIB.H C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/InitDevice.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/circle_slider.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/tick.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h

src/touchy.OBJ: C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Register_Enums.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/touchy.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/circle_slider.h C:/Users/kburzinski/SimplicityStudio/v4_workspace/BoldportTouchyIOFirmware/inc/config/cslib_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Lib/efm8_capsense/cslib.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/EFM8SB1/inc/SI_EFM8SB1_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.4/Device/shared/si8051Base/stdbool.h


