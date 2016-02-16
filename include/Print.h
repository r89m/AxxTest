//
// Created by Richard on 01/12/2015.
//

#ifndef TESTS_PRINT_H
#define TESTS_PRINT_H

#include <string>
#include <sstream>

// Interface copied from Arduino
// https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/cores/arduino/Print.h

class Print {

	private:
		void print(std::string);
		void println(std::string);
	

  public:
    void print(const char*);
    void print(int);
	void println();
    void println(const char*);
    void println(int);
    
    void clear_buffer();
	
	
	std::string buffer;
    

};


#endif //TESTS_PRINT_H
