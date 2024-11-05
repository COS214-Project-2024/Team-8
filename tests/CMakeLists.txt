
cmake_minimum_required(VERSION 3.10)
project(TaxationSystem)

# Add C++11 standard support
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the test executable
add_executable(run_taxation_tests TaxationSystemDocTest.cpp)

# If you want to use a separate build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
