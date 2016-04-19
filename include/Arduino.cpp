#include "Arduino.h"
#include "IArduinoHardware.h"
#include "fakeit.hpp"


// TODO: mock.reset - probably need an AxxTest::TestSuite class
// TODO: store digitalWrite, analogWrite, pinMode etc in ArduinoHardware class

using namespace fakeit;

IArduinoHardware* arduino;
Mock<IArduinoHardware> ArduinoHardwareMock;

void init_arduino_mock(){

	arduino = &ArduinoHardwareMock.get();
	
	When(Method(ArduinoHardwareMock, pinMode)).AlwaysReturn();
	When(Method(ArduinoHardwareMock, digitalRead)).AlwaysReturn(0);
	When(Method(ArduinoHardwareMock, digitalWrite)).AlwaysReturn();
	When(Method(ArduinoHardwareMock, analogRead)).AlwaysReturn(0);
	When(Method(ArduinoHardwareMock, analogWrite)).AlwaysReturn();
	When(Method(ArduinoHardwareMock, millis)).AlwaysReturn(0);
	
	std::cout << "Init called" << std::endl;
}

uint32_t fake_millis_value = 0;

int pin_modes[TEST_PIN_COUNT];
int pin_digital_write[TEST_PIN_COUNT];
int pin_digital_read[TEST_PIN_COUNT];
int pin_analog_write[TEST_PIN_COUNT];
int pin_analog_read[TEST_PIN_COUNT];


uint32_t millis(void){
	
	return arduino->millis();
}

void delay(uint32_t ms_delay){
	
	// Do nothing. Use the FakeIt mocking methods to cause millis to return different values
}

void pinMode(int pin, int mode){
	
	pin_modes[pin] = mode;
	arduino->pinMode(pin, mode);
}

void analogWrite(int pin, int value){
	
	pin_analog_write[pin] = value;
	arduino->analogWrite(pin, value);
}

int analogRead(int pin){
	
	return arduino->analogRead(pin);
}

void digitalWrite(int pin, int state){
	
	pin_digital_write[pin] = state;
	arduino->digitalWrite(pin, state);
}

int digitalRead(int pin){
	
	return arduino->digitalRead(pin);
}




void AxxTest_millis(uint32_t new_value){
	
	fake_millis_value = new_value;
	When(Method(ArduinoHardwareMock, millis)).AlwaysReturn(new_value);
}

void AxxTest_digitalRead(int pin, int state){
	
	When(Method(ArduinoHardwareMock, digitalRead).Using(pin)).AlwaysReturn(state);
}

void AxxTest_analogRead(int pin, int value){
	
	When(Method(ArduinoHardwareMock, analogRead).Using(pin)).AlwaysReturn(value);
}
