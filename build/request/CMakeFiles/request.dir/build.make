# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shrief/Desktop/File_Handler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shrief/Desktop/File_Handler/build

# Include any dependencies generated for this target.
include request/CMakeFiles/request.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include request/CMakeFiles/request.dir/compiler_depend.make

# Include the progress variables for this target.
include request/CMakeFiles/request.dir/progress.make

# Include the compile flags for this target's objects.
include request/CMakeFiles/request.dir/flags.make

request/CMakeFiles/request.dir/request.cpp.o: request/CMakeFiles/request.dir/flags.make
request/CMakeFiles/request.dir/request.cpp.o: ../request/request.cpp
request/CMakeFiles/request.dir/request.cpp.o: request/CMakeFiles/request.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shrief/Desktop/File_Handler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object request/CMakeFiles/request.dir/request.cpp.o"
	cd /home/shrief/Desktop/File_Handler/build/request && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT request/CMakeFiles/request.dir/request.cpp.o -MF CMakeFiles/request.dir/request.cpp.o.d -o CMakeFiles/request.dir/request.cpp.o -c /home/shrief/Desktop/File_Handler/request/request.cpp

request/CMakeFiles/request.dir/request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/request.dir/request.cpp.i"
	cd /home/shrief/Desktop/File_Handler/build/request && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shrief/Desktop/File_Handler/request/request.cpp > CMakeFiles/request.dir/request.cpp.i

request/CMakeFiles/request.dir/request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/request.dir/request.cpp.s"
	cd /home/shrief/Desktop/File_Handler/build/request && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shrief/Desktop/File_Handler/request/request.cpp -o CMakeFiles/request.dir/request.cpp.s

request/CMakeFiles/request.dir/RQ_main.cpp.o: request/CMakeFiles/request.dir/flags.make
request/CMakeFiles/request.dir/RQ_main.cpp.o: ../request/RQ_main.cpp
request/CMakeFiles/request.dir/RQ_main.cpp.o: request/CMakeFiles/request.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shrief/Desktop/File_Handler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object request/CMakeFiles/request.dir/RQ_main.cpp.o"
	cd /home/shrief/Desktop/File_Handler/build/request && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT request/CMakeFiles/request.dir/RQ_main.cpp.o -MF CMakeFiles/request.dir/RQ_main.cpp.o.d -o CMakeFiles/request.dir/RQ_main.cpp.o -c /home/shrief/Desktop/File_Handler/request/RQ_main.cpp

request/CMakeFiles/request.dir/RQ_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/request.dir/RQ_main.cpp.i"
	cd /home/shrief/Desktop/File_Handler/build/request && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shrief/Desktop/File_Handler/request/RQ_main.cpp > CMakeFiles/request.dir/RQ_main.cpp.i

request/CMakeFiles/request.dir/RQ_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/request.dir/RQ_main.cpp.s"
	cd /home/shrief/Desktop/File_Handler/build/request && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shrief/Desktop/File_Handler/request/RQ_main.cpp -o CMakeFiles/request.dir/RQ_main.cpp.s

# Object files for target request
request_OBJECTS = \
"CMakeFiles/request.dir/request.cpp.o" \
"CMakeFiles/request.dir/RQ_main.cpp.o"

# External object files for target request
request_EXTERNAL_OBJECTS =

request/request: request/CMakeFiles/request.dir/request.cpp.o
request/request: request/CMakeFiles/request.dir/RQ_main.cpp.o
request/request: request/CMakeFiles/request.dir/build.make
request/request: logger/libsimpleLogger.a
request/request: /usr/lib/x86_64-linux-gnu/libboost_log_setup.so.1.74.0
request/request: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.74.0
request/request: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.74.0
request/request: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
request/request: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.74.0
request/request: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
request/request: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
request/request: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
request/request: request/CMakeFiles/request.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shrief/Desktop/File_Handler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable request"
	cd /home/shrief/Desktop/File_Handler/build/request && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/request.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
request/CMakeFiles/request.dir/build: request/request
.PHONY : request/CMakeFiles/request.dir/build

request/CMakeFiles/request.dir/clean:
	cd /home/shrief/Desktop/File_Handler/build/request && $(CMAKE_COMMAND) -P CMakeFiles/request.dir/cmake_clean.cmake
.PHONY : request/CMakeFiles/request.dir/clean

request/CMakeFiles/request.dir/depend:
	cd /home/shrief/Desktop/File_Handler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shrief/Desktop/File_Handler /home/shrief/Desktop/File_Handler/request /home/shrief/Desktop/File_Handler/build /home/shrief/Desktop/File_Handler/build/request /home/shrief/Desktop/File_Handler/build/request/CMakeFiles/request.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : request/CMakeFiles/request.dir/depend

