################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include obj/Debug/src/subdir.mk
-include Tools/pdcurs34/x11/subdir.mk
-include Tools/pdcurs34/win32/subdir.mk
-include Tools/pdcurs34/sdl1/subdir.mk
-include Tools/pdcurs34/pdcurses/subdir.mk
-include Tools/pdcurs34/os2/subdir.mk
-include Tools/pdcurs34/dos/subdir.mk
-include Tools/pdcurs34/doc/subdir.mk
-include Tools/pdcurs34/demos/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ETA

# Tool invocations
ETA: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc  -o "ETA" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ETA
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
