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
include file_handler/CMakeFiles/fh.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include file_handler/CMakeFiles/fh.dir/compiler_depend.make

# Include the progress variables for this target.
include file_handler/CMakeFiles/fh.dir/progress.make

# Include the compile flags for this target's objects.
include file_handler/CMakeFiles/fh.dir/flags.make

file_handler/CMakeFiles/fh.dir/fh.cpp.o: file_handler/CMakeFiles/fh.dir/flags.make
file_handler/CMakeFiles/fh.dir/fh.cpp.o: ../file_handler/fh.cpp
file_handler/CMakeFiles/fh.dir/fh.cpp.o: file_handler/CMakeFiles/fh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shrief/Desktop/File_Handler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object file_handler/CMakeFiles/fh.dir/fh.cpp.o"
	cd /home/shrief/Desktop/File_Handler/build/file_handler && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT file_handler/CMakeFiles/fh.dir/fh.cpp.o -MF CMakeFiles/fh.dir/fh.cpp.o.d -o CMakeFiles/fh.dir/fh.cpp.o -c /home/shrief/Desktop/File_Handler/file_handler/fh.cpp

file_handler/CMakeFiles/fh.dir/fh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fh.dir/fh.cpp.i"
	cd /home/shrief/Desktop/File_Handler/build/file_handler && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shrief/Desktop/File_Handler/file_handler/fh.cpp > CMakeFiles/fh.dir/fh.cpp.i

file_handler/CMakeFiles/fh.dir/fh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fh.dir/fh.cpp.s"
	cd /home/shrief/Desktop/File_Handler/build/file_handler && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shrief/Desktop/File_Handler/file_handler/fh.cpp -o CMakeFiles/fh.dir/fh.cpp.s

file_handler/CMakeFiles/fh.dir/fh_main.cpp.o: file_handler/CMakeFiles/fh.dir/flags.make
file_handler/CMakeFiles/fh.dir/fh_main.cpp.o: ../file_handler/fh_main.cpp
file_handler/CMakeFiles/fh.dir/fh_main.cpp.o: file_handler/CMakeFiles/fh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shrief/Desktop/File_Handler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object file_handler/CMakeFiles/fh.dir/fh_main.cpp.o"
	cd /home/shrief/Desktop/File_Handler/build/file_handler && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT file_handler/CMakeFiles/fh.dir/fh_main.cpp.o -MF CMakeFiles/fh.dir/fh_main.cpp.o.d -o CMakeFiles/fh.dir/fh_main.cpp.o -c /home/shrief/Desktop/File_Handler/file_handler/fh_main.cpp

file_handler/CMakeFiles/fh.dir/fh_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fh.dir/fh_main.cpp.i"
	cd /home/shrief/Desktop/File_Handler/build/file_handler && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shrief/Desktop/File_Handler/file_handler/fh_main.cpp > CMakeFiles/fh.dir/fh_main.cpp.i

file_handler/CMakeFiles/fh.dir/fh_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fh.dir/fh_main.cpp.s"
	cd /home/shrief/Desktop/File_Handler/build/file_handler && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shrief/Desktop/File_Handler/file_handler/fh_main.cpp -o CMakeFiles/fh.dir/fh_main.cpp.s

# Object files for target fh
fh_OBJECTS = \
"CMakeFiles/fh.dir/fh.cpp.o" \
"CMakeFiles/fh.dir/fh_main.cpp.o"

# External object files for target fh
fh_EXTERNAL_OBJECTS =

file_handler/fh: file_handler/CMakeFiles/fh.dir/fh.cpp.o
file_handler/fh: file_handler/CMakeFiles/fh.dir/fh_main.cpp.o
file_handler/fh: file_handler/CMakeFiles/fh.dir/build.make
file_handler/fh: logger/libsimpleLogger.a
file_handler/fh: /usr/lib/x86_64-linux-gnu/libboost_log_setup.so.1.74.0
file_handler/fh: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.74.0
file_handler/fh: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.74.0
file_handler/fh: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
file_handler/fh: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.74.0
file_handler/fh: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
file_handler/fh: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
file_handler/fh: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
file_handler/fh: file_handler/CMakeFiles/fh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shrief/Desktop/File_Handler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable fh"
	cd /home/shrief/Desktop/File_Handler/build/file_handler && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
file_handler/CMakeFiles/fh.dir/build: file_handler/fh
.PHONY : file_handler/CMakeFiles/fh.dir/build

file_handler/CMakeFiles/fh.dir/clean:
	cd /home/shrief/Desktop/File_Handler/build/file_handler && $(CMAKE_COMMAND) -P CMakeFiles/fh.dir/cmake_clean.cmake
.PHONY : file_handler/CMakeFiles/fh.dir/clean

file_handler/CMakeFiles/fh.dir/depend:
	cd /home/shrief/Desktop/File_Handler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shrief/Desktop/File_Handler /home/shrief/Desktop/File_Handler/file_handler /home/shrief/Desktop/File_Handler/build /home/shrief/Desktop/File_Handler/build/file_handler /home/shrief/Desktop/File_Handler/build/file_handler/CMakeFiles/fh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : file_handler/CMakeFiles/fh.dir/depend
