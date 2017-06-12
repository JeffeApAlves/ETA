################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tools/pdcurs34/win32/pdcclip.c \
../Tools/pdcurs34/win32/pdcdisp.c \
../Tools/pdcurs34/win32/pdcgetsc.c \
../Tools/pdcurs34/win32/pdckbd.c \
../Tools/pdcurs34/win32/pdcscrn.c \
../Tools/pdcurs34/win32/pdcsetsc.c \
../Tools/pdcurs34/win32/pdcutil.c 

O_SRCS += \
../Tools/pdcurs34/win32/addch.o \
../Tools/pdcurs34/win32/addchstr.o \
../Tools/pdcurs34/win32/addstr.o \
../Tools/pdcurs34/win32/attr.o \
../Tools/pdcurs34/win32/beep.o \
../Tools/pdcurs34/win32/bkgd.o \
../Tools/pdcurs34/win32/border.o \
../Tools/pdcurs34/win32/clear.o \
../Tools/pdcurs34/win32/color.o \
../Tools/pdcurs34/win32/debug.o \
../Tools/pdcurs34/win32/delch.o \
../Tools/pdcurs34/win32/deleteln.o \
../Tools/pdcurs34/win32/deprec.o \
../Tools/pdcurs34/win32/getch.o \
../Tools/pdcurs34/win32/getstr.o \
../Tools/pdcurs34/win32/getyx.o \
../Tools/pdcurs34/win32/inch.o \
../Tools/pdcurs34/win32/inchstr.o \
../Tools/pdcurs34/win32/initscr.o \
../Tools/pdcurs34/win32/inopts.o \
../Tools/pdcurs34/win32/insch.o \
../Tools/pdcurs34/win32/insstr.o \
../Tools/pdcurs34/win32/instr.o \
../Tools/pdcurs34/win32/kernel.o \
../Tools/pdcurs34/win32/keyname.o \
../Tools/pdcurs34/win32/mouse.o \
../Tools/pdcurs34/win32/move.o \
../Tools/pdcurs34/win32/outopts.o \
../Tools/pdcurs34/win32/overlay.o \
../Tools/pdcurs34/win32/pad.o \
../Tools/pdcurs34/win32/panel.o \
../Tools/pdcurs34/win32/pdcclip.o \
../Tools/pdcurs34/win32/pdcdisp.o \
../Tools/pdcurs34/win32/pdcgetsc.o \
../Tools/pdcurs34/win32/pdckbd.o \
../Tools/pdcurs34/win32/pdcscrn.o \
../Tools/pdcurs34/win32/pdcsetsc.o \
../Tools/pdcurs34/win32/pdcutil.o \
../Tools/pdcurs34/win32/printw.o \
../Tools/pdcurs34/win32/refresh.o \
../Tools/pdcurs34/win32/scanw.o \
../Tools/pdcurs34/win32/scr_dump.o \
../Tools/pdcurs34/win32/scroll.o \
../Tools/pdcurs34/win32/slk.o \
../Tools/pdcurs34/win32/termattr.o \
../Tools/pdcurs34/win32/terminfo.o \
../Tools/pdcurs34/win32/touch.o \
../Tools/pdcurs34/win32/tui.o \
../Tools/pdcurs34/win32/tuidemo.o \
../Tools/pdcurs34/win32/util.o \
../Tools/pdcurs34/win32/window.o 

OBJS += \
./Tools/pdcurs34/win32/pdcclip.o \
./Tools/pdcurs34/win32/pdcdisp.o \
./Tools/pdcurs34/win32/pdcgetsc.o \
./Tools/pdcurs34/win32/pdckbd.o \
./Tools/pdcurs34/win32/pdcscrn.o \
./Tools/pdcurs34/win32/pdcsetsc.o \
./Tools/pdcurs34/win32/pdcutil.o 

C_DEPS += \
./Tools/pdcurs34/win32/pdcclip.d \
./Tools/pdcurs34/win32/pdcdisp.d \
./Tools/pdcurs34/win32/pdcgetsc.d \
./Tools/pdcurs34/win32/pdckbd.d \
./Tools/pdcurs34/win32/pdcscrn.d \
./Tools/pdcurs34/win32/pdcsetsc.d \
./Tools/pdcurs34/win32/pdcutil.d 


# Each subdirectory must supply rules for building sources it contributes
Tools/pdcurs34/win32/%.o: ../Tools/pdcurs34/win32/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


