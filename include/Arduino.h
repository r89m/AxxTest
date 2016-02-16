//
// Created by Richard on 01/12/2015.
//

#ifndef TESTS_ARDUINO_H
#define TESTS_ARDUINO_H

#include <iostream>
#include <stdint.h>
#include <stdlib.h>
//#include <string.h>
#include <math.h>

#define OUTPUT 4
#define LOW 0

typedef unsigned char byte;
typedef unsigned char boolean;

uint32_t millis(void);
void pinMode(int, int);
void analogWrite(int, int);
void digitalWrite(int, int);
int digitalRead(int);
int analogRead(int);

#define TEST_PIN_COUNT 50
extern int pin_modes[TEST_PIN_COUNT];
extern int pin_digital_write[TEST_PIN_COUNT];
extern int pin_digital_read[TEST_PIN_COUNT];
extern int pin_analog_write[TEST_PIN_COUNT];
extern int pin_analog_read[TEST_PIN_COUNT];

void AxxTest_millis(uint32_t);
void AxxTest_digitalRead(int, int);
void AxxTest_analogRead(int, int);


#define PSTR(str)(str)

#include "Print.h"
#include "File.h"
#include "Serial.h"
#include "WString.h"

#endif //TESTS_ARDUINO_H
