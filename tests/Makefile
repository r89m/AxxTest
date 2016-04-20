CXX=g++
CFLAGS= -c -std=c++11 -I ../include -I ../cxxtest-4.4 -I ../
LDFLAGS=
SOURCES=$(wildcard fakes/*.cpp) ../include/Arduino.cpp
OBJECTS=$(SOURCES:.cpp=.o) AxxTest.o


# Build all the Unit Tests ready to be run
all: buildTestsAxxTest

# Build and run all the Unit Tests
test: testAxxTest
	
	
# Build the Unit Under Test
unitUnderTest: ../include/AxxTest.cpp ../include/AxxTest.h
	@echo "Compile Unit Under Test"
	@$(CXX) $(CFLAGS) ../include/AxxTest.cpp
	

###########################################
#####        AxxTest Tests       ##########
###########################################

testAxxTest: buildTestsAxxTest
	@runners/AxxTestTests.exe || true
	

buildTestsAxxTest: unitUnderTest updateTestsAxxTest $(OBJECTS)  
	@echo "Build AxxTestTests"
	@$(CXX) $(LDFLAGS) $(OBJECTS) AxxTestTests.o -o runners/AxxTestTests.exe
	
	
updateTestsAxxTest: AxxTestTests.h
	@echo "Generate AxxTestTests class"
	@test -d runners || mkdir runners
	@../cxxtest-4.4/bin/cxxtestgen --error-printer -w "AxxTestTests" -o runners/AxxTestTests.cpp AxxTestTests.h
	@$(CXX) $(CFLAGS) runners/AxxTestTests.cpp
	

.cpp.o:
	@echo "Compile source ($<)"
	@$(CXX) $(CFLAGS) $< -o $@
	
clean:
	rm */*.o