################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tools/pdcurs34/x11/ScrollBox.c \
../Tools/pdcurs34/x11/pdcclip.c \
../Tools/pdcurs34/x11/pdcdisp.c \
../Tools/pdcurs34/x11/pdcgetsc.c \
../Tools/pdcurs34/x11/pdckbd.c \
../Tools/pdcurs34/x11/pdcscrn.c \
../Tools/pdcurs34/x11/pdcsetsc.c \
../Tools/pdcurs34/x11/pdcutil.c \
../Tools/pdcurs34/x11/pdcx11.c \
../Tools/pdcurs34/x11/sb.c \
../Tools/pdcurs34/x11/x11.c 

OBJS += \
./Tools/pdcurs34/x11/ScrollBox.o \
./Tools/pdcurs34/x11/pdcclip.o \
./Tools/pdcurs34/x11/pdcdisp.o \
./Tools/pdcurs34/x11/pdcgetsc.o \
./Tools/pdcurs34/x11/pdckbd.o \
./Tools/pdcurs34/x11/pdcscrn.o \
./Tools/pdcurs34/x11/pdcsetsc.o \
./Tools/pdcurs34/x11/pdcutil.o \
./Tools/pdcurs34/x11/pdcx11.o \
./Tools/pdcurs34/x11/sb.o \
./Tools/pdcurs34/x11/x11.o 

C_DEPS += \
./Tools/pdcurs34/x11/ScrollBox.d \
./Tools/pdcurs34/x11/pdcclip.d \
./Tools/pdcurs34/x11/pdcdisp.d \
./Tools/pdcurs34/x11/pdcgetsc.d \
./Tools/pdcurs34/x11/pdckbd.d \
./Tools/pdcurs34/x11/pdcscrn.d \
./Tools/pdcurs34/x11/pdcsetsc.d \
./Tools/pdcurs34/x11/pdcutil.d \
./Tools/pdcurs34/x11/pdcx11.d \
./Tools/pdcurs34/x11/sb.d \
./Tools/pdcurs34/x11/x11.d 


# Each subdirectory must supply rules for building sources it contributes
Tools/pdcurs34/x11/%.o: ../Tools/pdcurs34/x11/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


