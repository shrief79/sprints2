cmake_minimum_required(VERSION 3.10)
project(project)

# # Locate GTest package
find_package(GTest REQUIRED)

# # Add your test executable
# add_executable(test_request test_request.cpp )

# # Link against GTest
 

# # Add include directories
# target_include_directories(your_tests PRIVATE
#     ${CMAKE_SOURCE_DIR}
#     # ... Add any additional include directories here
# )

# Define the test source files
set(TEST_REQUEST_FILES test_request.cpp ../request/request.cpp)
set(TEST_FH_FILES test_fh.cpp ../file_handler/fh.cpp)

# Create an executable for the tests
add_executable(test_request ${TEST_REQUEST_FILES})
add_executable(test_fh ${TEST_FH_FILES})
target_link_libraries(test_request
   GTest::GTest
   GTest::Main
   -lgtest -lgtest_main -pthread
)
target_link_libraries(test_fh
    PRIVATE
   GTest::GTest
   GTest::Main
   -lgtest -lgtest_main -pthread
   -lrt
   -lpthread
   simpleLogger
)

# Link the test executable with the Google Test and your library
#target_link_libraries(tests gtest gtest_main my_library)

# Register the tests with CTest
include(GoogleTest)
gtest_discover_tests(test_request)

gtest_discover_tests(test_fh)