//
// Created by Richard on 01/12/2015.
//

#include "Print.h"

void Print::print(std::string to_print){
	
	buffer.append(to_print);
}

void Print::print(const char* to_print){
	
	buffer.append(to_print);
}

void Print::print(int to_print){
	
	std::ostringstream ss;
	ss << to_print;

	buffer.append(ss.str());
}

void Print::println(){
	
	char newline[] = "\n";
	print(newline);
}

void Print::println(std::string to_print){
	
	print(to_print);
	println();
}

void Print::println(const char* to_print){

	print(to_print);
	println();
}

void Print::println(int to_print){

	print(to_print);
	println();
}

void Print::clear_buffer(){
    
    buffer.clear();
}