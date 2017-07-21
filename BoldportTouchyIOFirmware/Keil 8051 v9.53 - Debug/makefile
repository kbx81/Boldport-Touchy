################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Keil tools exit code 1 is warnings only, so don't treat as an error in make
RC := test $$? -lt 2

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include lib/efm8sb1/cslib/serial_interface/subdir.mk
-include lib/efm8sb1/cslib/device_layer/subdir.mk
-include lib/cslib/application_layer/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: BoldportTouchyIOFirmware.omf

# Tool invocations
BoldportTouchyIOFirmware.omf: echo_path $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Keil 8051 Linker'
	LX51 "@BoldportTouchyIOFirmware.lnp" || $(RC)
	@echo 'Finished building target: $@'

# Change from all upper case to the expected case
	@-mv "BOLDPORTTOUCHYIOFIRMWARE.OMF.CRBUILD" "$@"

# Generate hex file: BoldportTouchyIOFirmware.hex
	@Ohx51 "BoldportTouchyIOFirmware.omf" "HEXFILE (BoldportTouchyIOFirmware.hex)" "H386" 2>&1 >/dev/null

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS) BoldportTouchyIOFirmware.omf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
# echo the path
echo_path:
	@echo PATH=$$PATH
	@echo ' '

