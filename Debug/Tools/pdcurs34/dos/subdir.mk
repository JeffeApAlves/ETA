################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tools/pdcurs34/dos/pdcclip.c \
../Tools/pdcurs34/dos/pdcdisp.c \
../Tools/pdcurs34/dos/pdcgetsc.c \
../Tools/pdcurs34/dos/pdckbd.c \
../Tools/pdcurs34/dos/pdcscrn.c \
../Tools/pdcurs34/dos/pdcsetsc.c \
../Tools/pdcurs34/dos/pdcutil.c 

OBJS += \
./Tools/pdcurs34/dos/pdcclip.o \
./Tools/pdcurs34/dos/pdcdisp.o \
./Tools/pdcurs34/dos/pdcgetsc.o \
./Tools/pdcurs34/dos/pdckbd.o \
./Tools/pdcurs34/dos/pdcscrn.o \
./Tools/pdcurs34/dos/pdcsetsc.o \
./Tools/pdcurs34/dos/pdcutil.o 

C_DEPS += \
./Tools/pdcurs34/dos/pdcclip.d \
./Tools/pdcurs34/dos/pdcdisp.d \
./Tools/pdcurs34/dos/pdcgetsc.d \
./Tools/pdcurs34/dos/pdckbd.d \
./Tools/pdcurs34/dos/pdcscrn.d \
./Tools/pdcurs34/dos/pdcsetsc.d \
./Tools/pdcurs34/dos/pdcutil.d 


# Each subdirectory must supply rules for building sources it contributes
Tools/pdcurs34/dos/%.o: ../Tools/pdcurs34/dos/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


