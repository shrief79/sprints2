if(EXISTS "/home/shrief/Desktop/File_Handler/build/Gtest/test_request[1]_tests.cmake")
  include("/home/shrief/Desktop/File_Handler/build/Gtest/test_request[1]_tests.cmake")
else()
  add_test(test_request_NOT_BUILT test_request_NOT_BUILT)
endif()