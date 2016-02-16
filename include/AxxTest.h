//
// Created by Richard on 01/12/2015.
//

#ifndef _AXXTEST_H
#define _AXXTEST_H

#include "cxxtest/TestSuite.h"
#include <stdio.h>

#define TS_ASSERT_PIN_MODE(pin, mode) TS_ASSERT_EQUALS(pin_modes[pin], mode)
#define TS_ASSERT_DIGITAL_WRITE(pin, state) TS_ASSERT_EQUALS(pin_digital_write[pin], state)
#define TS_ASSERT_ANALOG_WRITE(pin, value) TS_ASSERT_EQUALS(pin_analog_write[pin], value)


#endif //_AXXTEST_H
