################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RCC/rcc.c 

OBJS += \
./RCC/rcc.o 

C_DEPS += \
./RCC/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
RCC/rcc.o: ../RCC/rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F3 -DDEBUG -DSTM32F303RETx -DNUCLEO_F303RE -c -I../Inc -I"E:/WS/NTI_4M/Mini_RTOS/LIB" -I"E:/WS/NTI_4M/Mini_RTOS/RCC" -I"E:/WS/NTI_4M/Mini_RTOS/sysctick" -I"E:/WS/NTI_4M/Mini_RTOS/systick" -I"E:/WS/NTI_4M/Mini_RTOS/dio" -I"E:/WS/NTI_4M/Mini_RTOS/schedular" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"RCC/rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

