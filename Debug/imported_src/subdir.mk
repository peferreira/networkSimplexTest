################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/pedro/workspace/simplex_for_networks/src/Edge.cpp \
/home/pedro/workspace/simplex_for_networks/src/Graph.cpp \
/home/pedro/workspace/simplex_for_networks/src/InputReader.cpp 

OBJS += \
./imported_src/Edge.o \
./imported_src/Graph.o \
./imported_src/InputReader.o 

CPP_DEPS += \
./imported_src/Edge.d \
./imported_src/Graph.d \
./imported_src/InputReader.d 


# Each subdirectory must supply rules for building sources it contributes
imported_src/Edge.o: /home/pedro/workspace/simplex_for_networks/src/Edge.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

imported_src/Graph.o: /home/pedro/workspace/simplex_for_networks/src/Graph.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

imported_src/InputReader.o: /home/pedro/workspace/simplex_for_networks/src/InputReader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


