#C++ multilbrary

This project shows how usual tools like cmake, gtest, ctest, cpack and github can be used togther to manage a *multi-library* project.

## Project structure
The project is structured as a set of ``components``. A **component** is a directory structured as follows:
```bash
component\
  inc\
  src\
  CMakeLists.txt
```
Each component corresponds to a library that can be compiled as being static or shared (CMake paramater).
The global settings of the project are given in the first lines of the `CMakeLists.txt`.


## How to build and install the library
CMake is used as a "build" system. We deploy a set of libraries that can be activated or not 
depending on the corresponding options that ar given in the main `CMakeLists.txt`
### Building and install with cmake commands
Show Debug and Release
The project can be simply installed following the next process
```bash
git clone ...
mkdir build
cd build
cmake ../cmake-example
make 
```
In order to build in ``Debug`` or ``Release``, the option bcan be given to cmake again.
### Installation procedure
The installation requires to indicate where to install the libraries. It is done during
the cmake configuration with the keyword `CMAKE_PREFIX_PATH`. Within a command line, it gives:
```bash
cmake -S source_dir -B build -DCMAKE_INSTALL_PREFIX=install_dir
```
Without specifing anything, it should try to install it in ``\usr\local\include`` and ``\usr\local\lib``.
```bash
cmake  --build build --target install
```

Run the following line to build and install 

### Check how libraries can be used by a program
The directory ``test_link`` contains a simple executable that requires our libraries
to be installed. Considering that our libraries are installed in  ``install_dir``

The next script shows the whole process where our librarie is installed and used by the test executable
```bash
git clone ...
cmake -S ../cmake_example -B build_lib -DCMAKE_INSTALL_PREFIX=local_install
cmake --build build_lib --target local_install
cmake -S ../cmake/example/test_link -B build_exe -DCMAKE_PREFIX_PATH=$('pwd')/local_install 
cmake --build build_exe
```
- The first line clone the source directory locally. 
- Second line prepares the build of
our libraries that will be done in the local directory `build_lib`. 
- Third line performs the building stage of the libraries and install them with the CMake configuration files into `local_install`
- Fourth line prepares the build of our test example into the local directory `build_exe`. **Important:** We have to add the ***absolute*** path to the directory where our libraries were installed!!!
- The last line build our test executable.


## Testing 
Test are performed at two coarse-grained levels: 
- unitary, with using goolge test
- system, with using ctest
## Code coverage
Code coverage is simply ensured using `gcov`

TODO

## Continuous integration 
This project is hosted by github and use Github actions.

TODO


## Python wrapping
A simple wrapper is proposed with the pybind11 library
TODO
### python testing
TODO