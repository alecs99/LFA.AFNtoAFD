# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alc/CLionProjects/POO/laborator8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alc/CLionProjects/POO/laborator8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/laborator8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/laborator8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laborator8.dir/flags.make

CMakeFiles/laborator8.dir/main.cpp.o: CMakeFiles/laborator8.dir/flags.make
CMakeFiles/laborator8.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alc/CLionProjects/POO/laborator8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/laborator8.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/laborator8.dir/main.cpp.o -c /Users/alc/CLionProjects/POO/laborator8/main.cpp

CMakeFiles/laborator8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laborator8.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alc/CLionProjects/POO/laborator8/main.cpp > CMakeFiles/laborator8.dir/main.cpp.i

CMakeFiles/laborator8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laborator8.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alc/CLionProjects/POO/laborator8/main.cpp -o CMakeFiles/laborator8.dir/main.cpp.s

# Object files for target laborator8
laborator8_OBJECTS = \
"CMakeFiles/laborator8.dir/main.cpp.o"

# External object files for target laborator8
laborator8_EXTERNAL_OBJECTS =

laborator8: CMakeFiles/laborator8.dir/main.cpp.o
laborator8: CMakeFiles/laborator8.dir/build.make
laborator8: CMakeFiles/laborator8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alc/CLionProjects/POO/laborator8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable laborator8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/laborator8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laborator8.dir/build: laborator8

.PHONY : CMakeFiles/laborator8.dir/build

CMakeFiles/laborator8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/laborator8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/laborator8.dir/clean

CMakeFiles/laborator8.dir/depend:
	cd /Users/alc/CLionProjects/POO/laborator8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alc/CLionProjects/POO/laborator8 /Users/alc/CLionProjects/POO/laborator8 /Users/alc/CLionProjects/POO/laborator8/cmake-build-debug /Users/alc/CLionProjects/POO/laborator8/cmake-build-debug /Users/alc/CLionProjects/POO/laborator8/cmake-build-debug/CMakeFiles/laborator8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laborator8.dir/depend

