################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../frdmkl26z/board.c \
../frdmkl26z/clock_config.c \
../frdmkl26z/pin_mux.c 

OBJS += \
./frdmkl26z/board.o \
./frdmkl26z/clock_config.o \
./frdmkl26z/pin_mux.o 

C_DEPS += \
./frdmkl26z/board.d \
./frdmkl26z/clock_config.d \
./frdmkl26z/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
frdmkl26z/%.o: ../frdmkl26z/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MKL26Z128VLH4_cm0plus -DCPU_MKL26Z128VLH4 -D__REDLIB__ -I"C:\KL26\workspace\ZF_Controller\source" -I"C:\KL26\workspace\ZF_Controller" -I"C:\KL26\workspace\ZF_Controller\drivers" -I"C:\KL26\workspace\ZF_Controller\frdmkl26z" -I"C:\KL26\workspace\ZF_Controller\startup" -I"C:\KL26\workspace\ZF_Controller\CMSIS" -I"C:\KL26\workspace\ZF_Controller\utilities" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


