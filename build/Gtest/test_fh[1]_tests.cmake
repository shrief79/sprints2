add_test( CommandsTest.LSCommandSuccess /home/shrief/Desktop/File_Handler/build/Gtest/test_fh [==[--gtest_filter=CommandsTest.LSCommandSuccess]==] --gtest_also_run_disabled_tests)
set_tests_properties( CommandsTest.LSCommandSuccess PROPERTIES WORKING_DIRECTORY /home/shrief/Desktop/File_Handler/build/Gtest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( CommandsTest.LSCommandFailurePopen /home/shrief/Desktop/File_Handler/build/Gtest/test_fh [==[--gtest_filter=CommandsTest.LSCommandFailurePopen]==] --gtest_also_run_disabled_tests)
set_tests_properties( CommandsTest.LSCommandFailurePopen PROPERTIES WORKING_DIRECTORY /home/shrief/Desktop/File_Handler/build/Gtest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( CommandsTest.ReadCommandSuccess /home/shrief/Desktop/File_Handler/build/Gtest/test_fh [==[--gtest_filter=CommandsTest.ReadCommandSuccess]==] --gtest_also_run_disabled_tests)
set_tests_properties( CommandsTest.ReadCommandSuccess PROPERTIES WORKING_DIRECTORY /home/shrief/Desktop/File_Handler/build/Gtest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( CommandsTest.ReadCommandFailureFopen /home/shrief/Desktop/File_Handler/build/Gtest/test_fh [==[--gtest_filter=CommandsTest.ReadCommandFailureFopen]==] --gtest_also_run_disabled_tests)
set_tests_properties( CommandsTest.ReadCommandFailureFopen PROPERTIES WORKING_DIRECTORY /home/shrief/Desktop/File_Handler/build/Gtest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( CommandsTest.ReadCommandFailureStat /home/shrief/Desktop/File_Handler/build/Gtest/test_fh [==[--gtest_filter=CommandsTest.ReadCommandFailureStat]==] --gtest_also_run_disabled_tests)
set_tests_properties( CommandsTest.ReadCommandFailureStat PROPERTIES WORKING_DIRECTORY /home/shrief/Desktop/File_Handler/build/Gtest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( test_fh_TESTS CommandsTest.LSCommandSuccess CommandsTest.LSCommandFailurePopen CommandsTest.ReadCommandSuccess CommandsTest.ReadCommandFailureFopen CommandsTest.ReadCommandFailureStat)
