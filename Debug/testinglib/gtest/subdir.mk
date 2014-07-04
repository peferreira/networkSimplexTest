################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../testinglib/gtest/gtest-all.cc 

OBJS += \
./testinglib/gtest/gtest-all.o 

CC_DEPS += \
./testinglib/gtest/gtest-all.d 


# Each subdirectory must supply rules for building sources it contributes
testinglib/gtest/%.o: ../testinglib/gtest/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/pedro/workspace/simplex_for_networks_testing/testinglib" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


