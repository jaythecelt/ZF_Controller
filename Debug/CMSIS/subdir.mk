################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/system_MKL26Z4.c 

OBJS += \
./CMSIS/system_MKL26Z4.o 

C_DEPS += \
./CMSIS/system_MKL26Z4.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/%.o: ../CMSIS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MKL26Z128VLH4_cm0plus -DCPU_MKL26Z128VLH4 -D__REDLIB__ -I"C:\KL26\workspace\ZF_Controller\source" -I"C:\KL26\workspace\ZF_Controller" -I"C:\KL26\workspace\ZF_Controller\drivers" -I"C:\KL26\workspace\ZF_Controller\frdmkl26z" -I"C:\KL26\workspace\ZF_Controller\startup" -I"C:\KL26\workspace\ZF_Controller\CMSIS" -I"C:\KL26\workspace\ZF_Controller\utilities" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


