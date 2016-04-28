#include "AxxTest.h"

// TODO: store digitalWrite, analogWrite, pinMode etc in ArduinoHardware class

IArduinoHardware* ArduinoHardware;
fakeit::Mock<IArduinoHardware> ArduinoHardwareMock;

uint32_t fake_millis_value = 0;

int pin_modes[TEST_PIN_COUNT];
int pin_digital_write[TEST_PIN_COUNT];
int pin_analog_write[TEST_PIN_COUNT];


uint32_t millis(void){
	
	return ArduinoHardware->millis();
}

uint32_t micros(void){
    
    return ArduinoHardware->micros();
}

void delay(uint32_t ms_delay){
	
	// Do nothing. Use the FakeIt mocking methods to cause millis to return different values
}

void delayMicroseconds(uint32_t micro_delay){
    
    // Do nothing. Use the FakeIt mocking methods to cause micros to return different values
}

void pinMode(int pin, int mode){
	
	pin_modes[pin] = mode;
	ArduinoHardware->pinMode(pin, mode);
}

void analogWrite(int pin, int value){
	
	pin_analog_write[pin] = value;
	ArduinoHardware->analogWrite(pin, value);
}

int analogRead(int pin){
	
	return ArduinoHardware->analogRead(pin);
}

void digitalWrite(int pin, int state){
	
	pin_digital_write[pin] = state;
	ArduinoHardware->digitalWrite(pin, state);
}

int digitalRead(int pin){
	
	return ArduinoHardware->digitalRead(pin);
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
