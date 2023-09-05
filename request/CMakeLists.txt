# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Set the project name to "file_handler"
project(request)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Create an executable named "request" by compiling the source files "request.cpp and "RQ_main.cpp"
add_executable(request request.cpp RQ_main.cpp)
#target_include_directories(request request.h)

# Link the "request" executable with the following libraries
target_link_libraries(request
    PRIVATE
    -lrt
    -lpthread
    simpleLogger
)



