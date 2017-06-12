################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tools/pdcurs34/sdl1/pdcclip.c \
../Tools/pdcurs34/sdl1/pdcdisp.c \
../Tools/pdcurs34/sdl1/pdcgetsc.c \
../Tools/pdcurs34/sdl1/pdckbd.c \
../Tools/pdcurs34/sdl1/pdcscrn.c \
../Tools/pdcurs34/sdl1/pdcsetsc.c \
../Tools/pdcurs34/sdl1/pdcutil.c \
../Tools/pdcurs34/sdl1/sdltest.c 

OBJS += \
./Tools/pdcurs34/sdl1/pdcclip.o \
./Tools/pdcurs34/sdl1/pdcdisp.o \
./Tools/pdcurs34/sdl1/pdcgetsc.o \
./Tools/pdcurs34/sdl1/pdckbd.o \
./Tools/pdcurs34/sdl1/pdcscrn.o \
./Tools/pdcurs34/sdl1/pdcsetsc.o \
./Tools/pdcurs34/sdl1/pdcutil.o \
./Tools/pdcurs34/sdl1/sdltest.o 

C_DEPS += \
./Tools/pdcurs34/sdl1/pdcclip.d \
./Tools/pdcurs34/sdl1/pdcdisp.d \
./Tools/pdcurs34/sdl1/pdcgetsc.d \
./Tools/pdcurs34/sdl1/pdckbd.d \
./Tools/pdcurs34/sdl1/pdcscrn.d \
./Tools/pdcurs34/sdl1/pdcsetsc.d \
./Tools/pdcurs34/sdl1/pdcutil.d \
./Tools/pdcurs34/sdl1/sdltest.d 


# Each subdirectory must supply rules for building sources it contributes
Tools/pdcurs34/sdl1/%.o: ../Tools/pdcurs34/sdl1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


