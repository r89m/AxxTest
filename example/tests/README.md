# Example Unit Tests
This folder contains the files to run Unit tests against the ExampleLib library.

## Setup

1. Create links to the AxxTest directories (`mklink` on Windows or `ln` on Linux or OSX):
    1. `ExampleLib/tests/axxtest` -> `AxxTest/include`
    2. `ExampleLib/tests/cxxtest-4.4` -> `AxxTest/cxxtest-4.4`
2. Ensure `make` and `g++` are available on the path. On Linux / OSX this should already be the case. On Windows use [MinGW](http://www.mingw.org/) to install the `mingw-developer-toolkit`. This will download both `make` and `g++` to your computer. You also need to ensure the MinGW executable folder (usually `C:\MinGW\bin`) is listed in your system's PATH variable.
3. Open the command prompt (`cmd`)
4. Navigate to the `ExampleLib/tests` directory.
5. Run `make test` to build and run the unit tests.

You should output similar to the following:
````
> make test
Compile Unit Under Test
Generate ExampleLibTests class
Build ExampleLibTests
Running ExampleLibTests tests (5 tests).....OK!
````
Congratulations! You've just run your first unit tests.

You can now use `ExampleLibTests.h` and the AxxTest and cxxtest documentation to learn how to write unit tests for your own libraries.
