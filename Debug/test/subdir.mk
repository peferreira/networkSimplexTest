################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/FirstTest.cpp \
../test/GraphTest.cpp \
../test/InputReaderTest.cpp \
../test/MainTest.cpp 

OBJS += \
./test/FirstTest.o \
./test/GraphTest.o \
./test/InputReaderTest.o \
./test/MainTest.o 

CPP_DEPS += \
./test/FirstTest.d \
./test/GraphTest.d \
./test/InputReaderTest.d \
./test/MainTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/pedro/workspace/simplex_for_networks_testing/testinglib" -I"/home/pedro/workspace/simplex_for_networks/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


