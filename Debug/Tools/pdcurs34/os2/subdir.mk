################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tools/pdcurs34/os2/pdcclip.c \
../Tools/pdcurs34/os2/pdcdisp.c \
../Tools/pdcurs34/os2/pdcgetsc.c \
../Tools/pdcurs34/os2/pdckbd.c \
../Tools/pdcurs34/os2/pdcscrn.c \
../Tools/pdcurs34/os2/pdcsetsc.c \
../Tools/pdcurs34/os2/pdcutil.c 

OBJS += \
./Tools/pdcurs34/os2/pdcclip.o \
./Tools/pdcurs34/os2/pdcdisp.o \
./Tools/pdcurs34/os2/pdcgetsc.o \
./Tools/pdcurs34/os2/pdckbd.o \
./Tools/pdcurs34/os2/pdcscrn.o \
./Tools/pdcurs34/os2/pdcsetsc.o \
./Tools/pdcurs34/os2/pdcutil.o 

C_DEPS += \
./Tools/pdcurs34/os2/pdcclip.d \
./Tools/pdcurs34/os2/pdcdisp.d \
./Tools/pdcurs34/os2/pdcgetsc.d \
./Tools/pdcurs34/os2/pdckbd.d \
./Tools/pdcurs34/os2/pdcscrn.d \
./Tools/pdcurs34/os2/pdcsetsc.d \
./Tools/pdcurs34/os2/pdcutil.d 


# Each subdirectory must supply rules for building sources it contributes
Tools/pdcurs34/os2/%.o: ../Tools/pdcurs34/os2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


