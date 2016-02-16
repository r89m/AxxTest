#ifndef _IEXAMPLELIB_H_
#define _IEXAMPLELIB_H_

// Create an interface using pure virtual public functions
class IExampleLib{
    
    public:
        virtual int simpleAddition(int, int)=0;
        virtual int simpleSubtraction(int, int)=0;
        virtual void simpleDigitalWrite(int, int)=0;
        virtual void simpleAnalogWrite(int, int)=0;
        virtual int simpleAnalogRead(int)=0;
        virtual int simpleMillis()=0;
    
};

#endif //_IEXAMPLELIB_H_