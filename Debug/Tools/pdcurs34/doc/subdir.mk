################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tools/pdcurs34/doc/manext.c 

OBJS += \
./Tools/pdcurs34/doc/manext.o 

C_DEPS += \
./Tools/pdcurs34/doc/manext.d 


# Each subdirectory must supply rules for building sources it contributes
Tools/pdcurs34/doc/%.o: ../Tools/pdcurs34/doc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


