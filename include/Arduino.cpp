#include "Arduino.h"
#include "IArduinoHardware.h"
#include "fakeit.hpp"

using namespace fakeit;
//using fakeit::When;
//using fakeit::Method;
//using fakeit::Return;

IArduinoHardware arduino;

void init_arduino_mock(){

	Mock<IArduinoHardware> ArduinoHardwareMock;

	arduino = ArduinoHardwareMock.get();
	
	When(Method(ArduinoHardwareMock, digitalRead)).Return(1);
	
	std::cout << "Init called" << std::endl;
	
}

uint32_t fake_millis_value = 0;

int pin_modes[TEST_PIN_COUNT];
int pin_digital_write[TEST_PIN_COUNT];
int pin_digital_read[TEST_PIN_COUNT];
int pin_analog_write[TEST_PIN_COUNT];
int pin_analog_read[TEST_PIN_COUNT];


uint32_t millis(void){
  return fake_millis_value;
}

void pinMode(int pin, int mode){
	
	pin_modes[pin] = mode;
}

void analogWrite(int pin, int value){
	
	pin_analog_write[pin] = value;
}

int analogRead(int pin){
	
	return pin_analog_read[pin];
}

void digitalWrite(int pin, int state){
	
	pin_digital_write[pin] = state;
	
	std::cout << "Digital read: " << pin << ":" << state << std::endl;
}

int digitalRead(int pin){
	
	std::cout << "Digital read: " << pin;
	
	return pin_digital_read[pin];
}




void AxxTest_millis(uint32_t new_value){
	
	fake_millis_value = new_value;
}

void AxxTest_digitalRead(int pin, int state){
	
	pin_digital_read[pin] = state;
}

void AxxTest_analogRead(int pin, int value){
	
	pin_analog_read[pin] = value;
}
