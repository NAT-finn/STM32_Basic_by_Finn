################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/SEGGER_RTT.c \
../Driver/Src/SEGGER_RTT_Syscalls_GCC.c \
../Driver/Src/SEGGER_RTT_printf.c \
../Driver/Src/stm32f103xx_gpio.c 

OBJS += \
./Driver/Src/SEGGER_RTT.o \
./Driver/Src/SEGGER_RTT_Syscalls_GCC.o \
./Driver/Src/SEGGER_RTT_printf.o \
./Driver/Src/stm32f103xx_gpio.o 

C_DEPS += \
./Driver/Src/SEGGER_RTT.d \
./Driver/Src/SEGGER_RTT_Syscalls_GCC.d \
./Driver/Src/SEGGER_RTT_printf.d \
./Driver/Src/stm32f103xx_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o Driver/Src/%.su Driver/Src/%.cyclo: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"C:/Users/Ancol/STM32CubeIDE/workspace_1.12.1/STM32_Basic_by_Finn/Driver/Config" -I../Inc -I"C:/Users/Ancol/STM32CubeIDE/workspace_1.12.1/STM32_Basic_by_Finn/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/SEGGER_RTT.cyclo ./Driver/Src/SEGGER_RTT.d ./Driver/Src/SEGGER_RTT.o ./Driver/Src/SEGGER_RTT.su ./Driver/Src/SEGGER_RTT_Syscalls_GCC.cyclo ./Driver/Src/SEGGER_RTT_Syscalls_GCC.d ./Driver/Src/SEGGER_RTT_Syscalls_GCC.o ./Driver/Src/SEGGER_RTT_Syscalls_GCC.su ./Driver/Src/SEGGER_RTT_printf.cyclo ./Driver/Src/SEGGER_RTT_printf.d ./Driver/Src/SEGGER_RTT_printf.o ./Driver/Src/SEGGER_RTT_printf.su ./Driver/Src/stm32f103xx_gpio.cyclo ./Driver/Src/stm32f103xx_gpio.d ./Driver/Src/stm32f103xx_gpio.o ./Driver/Src/stm32f103xx_gpio.su

.PHONY: clean-Driver-2f-Src

