#include "ExampleLib.h"

int ExampleLib::simpleAddition(int num_1, int num_2){
    
    return num_1 + num_2;
}

int ExampleLib::simpleSubtraction(int num_1, int num_2){
    
    return num_1 - num_2;
}

void ExampleLib::simpleDigitalWrite(int pin, int state){
    
    digitalWrite(pin, state);
}

void ExampleLib::simpleAnalogWrite(int pin, int value){
    
    analogWrite(pin, value);
}

int ExampleLib::simpleAnalogRead(int pin){
    
    return analogRead(pin);
}

int ExampleLib::simpleMillis(){
    
    return millis();
}