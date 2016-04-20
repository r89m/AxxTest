#include "AxxTest.h"

class AxxTestTests : public CxxTest::TestSuite{
        
    public:
  
        void setUp(){
            
            AxxTest::initialiseArduinoMock();
        }
		
		// Test pinMode
		void testPinModeInitialStateIsInput(){
			
			TS_ASSERT_PIN_MODE(1, INPUT);			// Min
			TS_ASSERT_PIN_MODE(25, INPUT);			// Mid
			TS_ASSERT_PIN_MODE(49, INPUT);			// Max
		}
		
		void testPinModeControl_Output(){
			
			pinMode(5, OUTPUT);
			TS_ASSERT_PIN_MODE(5, OUTPUT);
			
			pinMode(10, OUTPUT);
			TS_ASSERT_PIN_MODE(10, OUTPUT);
		}
		
		void testPinModeControl_InputPullup(){
			
			pinMode(5, INPUT_PULLUP);
			TS_ASSERT_PIN_MODE(5, INPUT_PULLUP);
			
			pinMode(10, INPUT_PULLUP);
			TS_ASSERT_PIN_MODE(10, INPUT_PULLUP);
		}
		
		void testPinModeControl_Input(){
			
			pinMode(5, OUTPUT);
			pinMode(5, INPUT);
			TS_ASSERT_PIN_MODE(5, INPUT);
			
			pinMode(10, OUTPUT);
			pinMode(10, INPUT);
			TS_ASSERT_PIN_MODE(10, INPUT);
		}
		
		void testPinModeControlInterference_Setup(){
			
			pinMode(5, OUTPUT);
			pinMode(10, INPUT_PULLUP);
		}
		
		void testPinModeCntrolInterference_Test(){
			
			TS_ASSERT_PIN_MODE(5, INPUT);
			TS_ASSERT_PIN_MODE(10, INPUT);
		}
		
		// Test digitalWrite
		void testDigitalWriteInitialStateIsLow(){
			
			TS_ASSERT_DIGITAL_WRITE(1, LOW);		// Min
			TS_ASSERT_DIGITAL_WRITE(25, LOW);		// Mid
			TS_ASSERT_DIGITAL_WRITE(49, LOW);		// Max
		}
		
		void testDigitalWrite(){
			
			digitalWrite(5, HIGH);
			TS_ASSERT_DIGITAL_WRITE(5, HIGH);
			
			digitalWrite(10, HIGH);
			TS_ASSERT_DIGITAL_WRITE(10, HIGH);
			digitalWrite(10, LOW);
			TS_ASSERT_DIGITAL_WRITE(10, LOW);
		}
		
		void testDigitalWrite_Interference_Setup(){
			
			digitalWrite(5, HIGH);
			digitalWrite(10, HIGH);
		}
		
		void testDigitalWriteInterference_Test(){
			
			TS_ASSERT_DIGITAL_WRITE(5, LOW);
			TS_ASSERT_DIGITAL_WRITE(10, LOW);
		}
		
		// Test digitalRead
		void testDigitalReadInitialStateIsLow(){
			
			TS_ASSERT_EQUALS(LOW, digitalRead(1));	// Min
			TS_ASSERT_EQUALS(LOW, digitalRead(25));	// Mid
			TS_ASSERT_EQUALS(LOW, digitalRead(50));	// Max
		}
		
		void testDigitalRead(){
			
			AxxTest_digitalRead(5, HIGH);
			TS_ASSERT_EQUALS(HIGH, digitalRead(5));
			
			AxxTest_digitalRead(10, HIGH);
			TS_ASSERT_EQUALS(HIGH, digitalRead(10));
			AxxTest_digitalRead(10, LOW);
			TS_ASSERT_EQUALS(LOW, digitalRead(10));
		}
		
		void testDigitalReadInterference_Setup(){
			
			AxxTest_digitalRead(5, HIGH);
			AxxTest_digitalRead(10, HIGH);
		}
		
		void testDigitalReadInterference_Test(){
			
			TS_ASSERT_EQUALS(LOW, digitalRead(5));
			TS_ASSERT_EQUALS(LOW, digitalRead(10));
		}
		
		void testDigitalReadLoop(){
			
			using namespace fakeit;
			
			When(Method(ArduinoHardwareMock, digitalRead).Using(10)).Return(5_Times(LOW)).Return(HIGH);
			
			int count;
			
			for(count = 0; count < 10; count++){
				if(digitalRead(10) == HIGH){
					break;
				}
			}
			
			TS_ASSERT_EQUALS(5, count);
		}
		
		// Test analogWrite
		void testAnalogWriteInitialStateIsLow(){
			
			TS_ASSERT_ANALOG_WRITE(1, LOW);			// Min
			TS_ASSERT_ANALOG_WRITE(25, LOW);		// Mid
			TS_ASSERT_ANALOG_WRITE(49, LOW);		// Max
		}
		
		void testAnalogWrite(){
			
			analogWrite(5, 100);
			TS_ASSERT_ANALOG_WRITE(5, 100);
			
			analogWrite(10, 176);
			TS_ASSERT_ANALOG_WRITE(10, 176);
		}
		
		void testAnalogWriteInterference_Setup(){
			
			analogWrite(5, 100);
			analogWrite(10, 176);
		}
		
		void testAnalogWriteInterference_Test(){
			
			TS_ASSERT_ANALOG_WRITE(5, LOW);
			TS_ASSERT_ANALOG_WRITE(10, LOW);
		}
		
		// Test analogRead
		void testAnalogReadInitialStateIsLow(){
			
			TS_ASSERT_EQUALS(LOW, analogRead(1));	// Min
			TS_ASSERT_EQUALS(LOW, analogRead(25));	// Mid
			TS_ASSERT_EQUALS(LOW, analogRead(49));	// Max
		}
		
		void testAnalogRead(){
			
			AxxTest_analogRead(5, 230);
			TS_ASSERT_EQUALS(230, analogRead(5));
			
			AxxTest_analogRead(10, 102);
			TS_ASSERT_EQUALS(102, analogRead(10));
		}
		
		void testAnalogReadInterference_Setup(){
			
			AxxTest_analogRead(5, 230);
			AxxTest_analogRead(10, 102);
		}
		
		void testAnalogReadInterference_Test(){
			
			TS_ASSERT_EQUALS(LOW, analogRead(5));
			TS_ASSERT_EQUALS(LOW, digitalRead(10));
		}
		
		void testAnalogReadLoop(){
			
			using namespace fakeit;
			
			When(Method(ArduinoHardwareMock, analogRead).Using(5)).Return(0, 14, 60, 90, 130, 160, 170, 200, 240);
			
			int count;
			
			for(count = 0; count < 10; count++){
				if(analogRead(5) > 150){
					break;
				}
			}
			
			TS_ASSERT_EQUALS(5, count);			
		}
		
		// Test millis
		void testMillisInitialState(){
			
			TS_ASSERT_EQUALS(0, millis());
		}
		
		void testMillisSimple(){
			
			AxxTest_millis(100);
			TS_ASSERT_EQUALS(100, millis());
			
			AxxTest_millis(400);
			TS_ASSERT_EQUALS(400, millis());
		}
		
		void testMillisInterference_Setup(){
			
			AxxTest_millis(500);
		}
		
		void testMillisInterference_Teset(){
			
			TS_ASSERT_EQUALS(0, millis());
		}
		
		void testMillisMocked(){
			
			using namespace fakeit;
				
			When(Method(ArduinoHardwareMock, millis)).Return(100, 300, 400);
			
			TS_ASSERT_EQUALS(100, millis());
			TS_ASSERT_EQUALS(300, millis());
			TS_ASSERT_EQUALS(400, millis());
		}
		
		void testMillisWithDelayLoop(){
			
			using namespace fakeit;
				
			When(Method(ArduinoHardwareMock, millis)).Return(100, 300, 400);
			
			int count;
			
			for(count = 0; count < 10; count++){
				if(millis() > 350){
					break;
				}
				delay(50);
			}
			
			TS_ASSERT_EQUALS(2, count);
		}
		
        
};