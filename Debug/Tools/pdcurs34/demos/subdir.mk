################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tools/pdcurs34/demos/firework.c \
../Tools/pdcurs34/demos/newdemo.c \
../Tools/pdcurs34/demos/ptest.c \
../Tools/pdcurs34/demos/rain.c \
../Tools/pdcurs34/demos/testcurs.c \
../Tools/pdcurs34/demos/tui.c \
../Tools/pdcurs34/demos/tuidemo.c \
../Tools/pdcurs34/demos/worm.c \
../Tools/pdcurs34/demos/xmas.c 

OBJS += \
./Tools/pdcurs34/demos/firework.o \
./Tools/pdcurs34/demos/newdemo.o \
./Tools/pdcurs34/demos/ptest.o \
./Tools/pdcurs34/demos/rain.o \
./Tools/pdcurs34/demos/testcurs.o \
./Tools/pdcurs34/demos/tui.o \
./Tools/pdcurs34/demos/tuidemo.o \
./Tools/pdcurs34/demos/worm.o \
./Tools/pdcurs34/demos/xmas.o 

C_DEPS += \
./Tools/pdcurs34/demos/firework.d \
./Tools/pdcurs34/demos/newdemo.d \
./Tools/pdcurs34/demos/ptest.d \
./Tools/pdcurs34/demos/rain.d \
./Tools/pdcurs34/demos/testcurs.d \
./Tools/pdcurs34/demos/tui.d \
./Tools/pdcurs34/demos/tuidemo.d \
./Tools/pdcurs34/demos/worm.d \
./Tools/pdcurs34/demos/xmas.d 


# Each subdirectory must supply rules for building sources it contributes
Tools/pdcurs34/demos/%.o: ../Tools/pdcurs34/demos/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


