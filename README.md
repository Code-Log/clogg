# CLogg

CLogg is a lightweight C++ logging library. It's really not any more complicated than it sounds.

## Building

### Prerequisites
 * CMake
 * Clang
 * MinGW (optionally on Windows)

### Linux

 1. Run the build.sh script, adding the desired build mode, e.g. `$ ./build.sh debug`
 2. In the previous step a build directory was generated, simply cd into that directory and run `$ make`

### Windows

 1. Create a directory to store your build files, e.g. `mkdir build`
 2. In the build directory, run `cmake ..` with your desired generator and options. If you don't know how to use cmake, you can use the following command to generate a Code::Blocks project: `cmake .. -G "CodeBlocks - MinGW Makefiles"`

## Installation

### Linux

 * All you need to do on linux is run `# make install` from the build directory.
 * Optionally, if you are on Ubuntu, you can install CLogg using Aptitude: `$ sudo apt-get install libclogg` should do the trick.

### Windows

To use CLogg in a project on Windows, first you need to compile the library using the aforementioned method, then you have to add the include directory to your include path and link against the compiled library. Pretty standard stuff.