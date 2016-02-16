# ExampleLib
This is an example library which has been written in a way to help ease the testing process.

An interface - `IExampleLib.h` - defines the API.

`ExampleLib.h` provides the an instance of the interface, and `ExampleLib.cpp` then provides the concrete implementation.

This structure makes it very easy to replace `ExampleLib` with your own library, so long as it extends the interface `IExampleLib`, which helps create more modular and therefore testable code.

The `tests` folder contains all that is required to unit test this library
