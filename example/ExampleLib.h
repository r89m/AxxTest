#ifndef _EXAMPLELIB_H_
#define _EXAMPLELIB_H_

#include "IExampleLib.h"

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

// Define class implementing interface
class ExampleLib : IExampleLib{
    
    public:
        virtual int simpleAddition(int, int);
        virtual int simpleSubtraction(int, int);
        virtual void simpleDigitalWrite(int, int);
        virtual void simpleAnalogWrite(int, int);
        virtual int simpleAnalogRead(int);
        virtual int simpleMillis();
    
};


#endif // _EXAMPLELIB_H_