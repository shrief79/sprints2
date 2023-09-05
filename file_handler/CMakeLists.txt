# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name and version
project(file_handler)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Create an executable named "fh" from source files fh.cpp and fh_main.cpp
add_executable(fh fh.cpp fh_main.cpp)

# Link the executable with the required libraries
target_link_libraries(fh
    PRIVATE
    -lrt        # Link with the Real-time Library
    -lpthread   # Link with the POSIX Threads Library
    simpleLogger # Link with the simpleLogger library (assuming it's defined elsewhere)
)
