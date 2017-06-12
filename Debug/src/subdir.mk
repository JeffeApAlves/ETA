################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/App.c \
../src/ConfigMenu.c \
../src/Container.c \
../src/DataAcquisition.c \
../src/DemoIncremental.c \
../src/DemoRandom.c \
../src/Dispenser.c \
../src/Display.c \
../src/ETA.c \
../src/FlowSensor.c \
../src/Key.c \
../src/MainForm.c \
../src/MainMenu.c \
../src/Menu.c \
../src/Misc.c \
../src/MonitorMenu.c \
../src/Pump.c \
../src/RBPI3.c \
../src/SimulatorMenu.c \
../src/Tank.c \
../src/TasksManager.c \
../src/Valve.c \
../src/main.c 

O_SRCS += \
../src/keyboard.o 

OBJS += \
./src/App.o \
./src/ConfigMenu.o \
./src/Container.o \
./src/DataAcquisition.o \
./src/DemoIncremental.o \
./src/DemoRandom.o \
./src/Dispenser.o \
./src/Display.o \
./src/ETA.o \
./src/FlowSensor.o \
./src/Key.o \
./src/MainForm.o \
./src/MainMenu.o \
./src/Menu.o \
./src/Misc.o \
./src/MonitorMenu.o \
./src/Pump.o \
./src/RBPI3.o \
./src/SimulatorMenu.o \
./src/Tank.o \
./src/TasksManager.o \
./src/Valve.o \
./src/main.o 

C_DEPS += \
./src/App.d \
./src/ConfigMenu.d \
./src/Container.d \
./src/DataAcquisition.d \
./src/DemoIncremental.d \
./src/DemoRandom.d \
./src/Dispenser.d \
./src/Display.d \
./src/ETA.d \
./src/FlowSensor.d \
./src/Key.d \
./src/MainForm.d \
./src/MainMenu.d \
./src/Menu.d \
./src/Misc.d \
./src/MonitorMenu.d \
./src/Pump.d \
./src/RBPI3.d \
./src/SimulatorMenu.d \
./src/Tank.d \
./src/TasksManager.d \
./src/Valve.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


