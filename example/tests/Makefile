CC=g++
CFLAGS= -c -std=c++11 -I axxtest -I cxxtest-4.4 -I ../
LDFLAGS=
SOURCES=$(wildcard fakes/*.cpp) axxtest/Arduino.cpp
OBJECTS=$(SOURCES:.cpp=.o) ExampleLib.o


# Build all the Unit Tests ready to be run
all: buildTestsExampleLib 

# Build and run all the Unit Tests
test: testExampleLib
	
	
# Build the Unit Under Test
unitUnderTest: ../ExampleLib.cpp ../ExampleLib.h
	@echo "Compile Unit Under Test"
	@$(CC) $(CFLAGS) ../ExampleLib.cpp
	

###########################################
#####       ExampleLib Tests     ##########
###########################################

testExampleLib: buildTestsExampleLib
	@runners/ExampleLibTests.exe || true
	

buildTestsExampleLib: unitUnderTest updateTestsExampleLib $(OBJECTS)  
	@echo "Build ExampleLibTests"
	@$(CC) $(LDFLAGS) $(OBJECTS) ExampleLibTests.o -o runners/ExampleLibTests.exe
	
	
updateTestsExampleLib: ExampleLibTests.h
	@echo "Generate ExampleLibTests class"
	@test -d runners || mkdir runners
	@cxxtest-4.4/bin/cxxtestgen --error-printer -w "ExampleLibTests" -o runners/ExampleLibTests.cpp ExampleLibTests.h
	@$(CC) $(CFLAGS) runners/ExampleLibTests.cpp
	
	

.cpp.o:
	@echo "Compile source"
	@$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm */*.o