#define CXXTEST_HAVE_EH
#define CXXTEST_ABORT_TEST_ON_FAIL
#include <cxxtest/ErrorPrinter.h>
#include <Arduino.h>

int main()
{
	init_arduino_mock();
    int status = CxxTest::ErrorPrinter().run();
    return status;
}

// The CxxTest "world"
<CxxTest world>