################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Adresse.cpp \
../ContratException.cpp \
../Date.cpp \
../Personne.cpp \
../personneMain.cpp \
../validationFormat.cpp 

OBJS += \
./Adresse.o \
./ContratException.o \
./Date.o \
./Personne.o \
./personneMain.o \
./validationFormat.o 

CPP_DEPS += \
./Adresse.d \
./ContratException.d \
./Date.d \
./Personne.d \
./personneMain.d \
./validationFormat.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


