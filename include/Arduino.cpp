#include "Arduino.h"


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

void digitalWrite(int pin, int value){
	
	pin_digital_write[pin] = value;
}

int digitalRead(int pin){
	
	return pin_digital_read[pin];
}




void AxxTest_millis(uint32_t new_value){
	
	fake_millis_value = new_value;
}

void AxxTest_digitalRead(int pin, int value){
	
	pin_digital_read[pin] = value;
}

void AxxTest_analogRead(int pin, int value){
	
	pin_analog_read[pin] = value;
}