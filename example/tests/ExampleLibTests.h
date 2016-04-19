#include "AxxTest.h"
#include "ExampleLib.h"

class ExampleLibTests : public CxxTest::TestSuite{

    private:
        ExampleLib el;

    public:
	
  
        void setUp(){
            
            // This is called before each test.
            // Use it to initialise any variables or objects you might need
			AxxTest::initialiseArduinoMock();
        }
      
        void testAddition(){
            
            int num_1 = 10;
            int num_2 = 30;
            int expected_result = num_1 + num_2;
            
            TS_ASSERT_EQUALS(expected_result, el.simpleAddition(num_1, num_2));
        }
      
        void testSubtraction(){
            
            int num_1 = 30;
            int num_2 = 10;
            int expected_result = num_1 - num_2;
            
            TS_ASSERT_EQUALS(expected_result, el.simpleSubtraction(num_1, num_2));
        }
        
        void testDigitalWrite(){
            
            int pin = 4;
            int state = HIGH;
            
            el.simpleDigitalWrite(pin, state);
            
            TS_ASSERT_DIGITAL_WRITE(pin, state);
        }
        
        void testAnalogWrite(){
            
            int pin = 6;
            int value = 140;
            
            el.simpleAnalogWrite(pin, value);
            
            TS_ASSERT_ANALOG_WRITE(pin, value);
        }
        
        void testAnalogRead(){
            
            int pin = 2;
            int value = 107;
            
            AxxTest_analogRead(pin, value);
            
            TS_ASSERT_EQUALS(value, el.simpleAnalogRead(pin));
        }
        
        void testMillis(){
            
            int desired_millis = 50;
            
            AxxTest_millis(desired_millis);
            
            TS_ASSERT_EQUALS(desired_millis, el.simpleMillis());
        }
  
};