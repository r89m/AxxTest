#include "AxxTest.h"

namespace AxxTest{
	
	void initialiseArduinoMock(){

		ArduinoHardwareMock.Reset();

		ArduinoHardware = &ArduinoHardwareMock.get();
		
		When(Method(ArduinoHardwareMock, pinMode)).AlwaysReturn();
		When(Method(ArduinoHardwareMock, digitalRead)).AlwaysReturn(0);
		When(Method(ArduinoHardwareMock, digitalWrite)).AlwaysReturn();
		When(Method(ArduinoHardwareMock, analogRead)).AlwaysReturn(0);
		When(Method(ArduinoHardwareMock, analogWrite)).AlwaysReturn();
		When(Method(ArduinoHardwareMock, millis)).AlwaysReturn(0);
	}
}