#include "AxxTest.h"

namespace AxxTest{
	
	void initialiseArduinoMock(){

		// Reset the Mock object
		ArduinoHardwareMock.Reset();

		ArduinoHardware = &ArduinoHardwareMock.get();
		
		// Recreate the default method responses
		When(Method(ArduinoHardwareMock, pinMode)).AlwaysReturn();
		When(Method(ArduinoHardwareMock, digitalRead)).AlwaysReturn(0);
		When(Method(ArduinoHardwareMock, digitalWrite)).AlwaysReturn();
		When(Method(ArduinoHardwareMock, analogRead)).AlwaysReturn(0);
		When(Method(ArduinoHardwareMock, analogWrite)).AlwaysReturn();
		When(Method(ArduinoHardwareMock, millis)).AlwaysReturn(0);
		
		// Reset the hardware variables - digitalWrite, analogWrite and pinMode
		for(int pin = 0; pin < TEST_PIN_COUNT; pin++){
			pin_modes[pin] = INPUT;
			pin_digital_write[pin] = LOW;
			pin_analog_write[pin] = LOW;
		}
	}
}