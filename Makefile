PWD=$(realpath ./)
TEST_DIR=$(PWD)/tests
CXX=g++
CFLAGS= -c -std=c++11 --coverage -fprofile-arcs -g -I $(PWD)/include -I $(PWD)/cxxtest-4.4 -I $(PWD)
LDFLAGS=--coverage -fprofile-arcs
SOURCES=$(PWD)/include/Arduino.cpp $(PWD)/include/AxxTest.cpp
OBJECTS=$(SOURCES:.cpp=.o)


# Build all the Unit Tests ready to be run
all: buildTestsAxxTest

# Build and run all the Unit Tests
test: testAxxTest
	
	
# Build the Unit Under Test
unitUnderTest: $(PWD)/include/AxxTest.cpp $(PWD)/include/AxxTest.h
	@echo "Compile Unit Under Test"
	@$(CXX) $(CFLAGS) $(PWD)/include/AxxTest.cpp -o $(PWD)/include/AxxTest.o
	

###########################################
#####        AxxTest Tests       ##########
###########################################

testAxxTest: buildTestsAxxTest
	@$(TEST_DIR)/runners/AxxTestTests.exe || true
	

buildTestsAxxTest: unitUnderTest updateTestsAxxTest $(OBJECTS)  
	@echo "Build AxxTestTests"
	@$(CXX) $(LDFLAGS) $(OBJECTS) $(TEST_DIR)/runners/AxxTestTests.o -o $(TEST_DIR)/runners/AxxTestTests.exe
	
	
updateTestsAxxTest: $(TEST_DIR)/AxxTestTests.h
	@echo "Generate AxxTestTests class"
	@test -d $(TEST_DIR)/runners || mkdir $(TEST_DIR)/runners
	@$(PWD)/cxxtest-4.4/bin/cxxtestgen --error-printer -w "AxxTestTests" -o $(TEST_DIR)/runners/AxxTestTests.cpp $(TEST_DIR)/AxxTestTests.h
	@$(CXX) $(CFLAGS) $(TEST_DIR)/runners/AxxTestTests.cpp -o $(TEST_DIR)/runners/AxxTestTests.o
	

.cpp.o:
	@echo "Compile source ($<)"
	@$(CXX) $(CFLAGS) $< -o $@
	
clean:
# Clean this folder
	@- rm *.o || true
	@- rm *.gcno || true
	@- rm *.gcda || true
	@- rm *.gcov || true
	
# Clear the tests/runners folder
	@- rm -rf tests/runners