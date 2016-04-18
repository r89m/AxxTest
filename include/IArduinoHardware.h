#ifndef _IARDUINOHARDWARE_H
#define _IARDUINOHARDWARE_H

#include "Arduino.h"

class IArduinoHardware{
	
	public:
		virtual uint8_t digitalRead(uint8_t pin)=0;
		virtual void digitalWrite(uint8_t pin, uint8_t state)=0;
		virtual uint16_t analogRead(uint8_t pin)=0;
		virtual void analogWrite(uint8_t pin, uint8_t pwm)=0;
		
	
};

#endif // _IARDUINOHARDWARE_H