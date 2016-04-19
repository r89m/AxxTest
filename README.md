# AxxTest

AxxTest is a unit testing framework for Arduino and Arduino-compatible code built upon the [CxxTest](http://cxxtest.com/) unit testing framework and the [FakeIt](https://github.com/eranpeer/FakeIt) Mocking Framework.

## Supported Hardware Features
In its current form it allows testing of pure C++ code as well as code making use of simple I/O and built-in functions such as:
* `digitalRead`

* `digitalWrite`

* `analogRead`

* `analogWrite`

* `millis`

* `SerialUSB`

## Setup
This framework requires `make` and `g++`. Please see the [example project's](example/tests) setup instructions for details.


## Assert Methods
In order to test some of the Arduino-specific code, it is necessary to use one of the new Assert methods that AxxTest provides:

* `TS_ASSERT_PIN_MODE(pin, mode);` - asserts that the given pin is set to the given mode

* `TS_ASSERT_DIGITAL_WRITE(pin, state);` - asserts that the given pin is set to the given state

* `TS_ASSERT_ANALOG_WRITE(pin, value);` - asserts that the given pin is set to the given value

## AxxTest_ Methods
Several `AxxTest_` prefixed methods are provided to allow dummy values to be provided to the code under test.

* `AxxTest_millis(new_millis)` - set the value that `millis()` will return, effectively controlling time.

* `AxxTest_digitalRead(pin, state)` - set the state of a digital pin that will be read later by the code under test.

* `AxxTest_analogRead(pin, value)` - set the value of an analog pin that will be read later by the code under test.

## Example
Please see the [example project](example/tests) to see how tests can be implemented to verify the functioning of your code that uses the above methods.
