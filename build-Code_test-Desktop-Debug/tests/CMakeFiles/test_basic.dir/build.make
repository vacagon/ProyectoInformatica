# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gonzalo/ProyectoInformatica/Code_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_basic.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_basic.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_basic.dir/flags.make

tests/CMakeFiles/test_basic.dir/test_basic.cpp.o: tests/CMakeFiles/test_basic.dir/flags.make
tests/CMakeFiles/test_basic.dir/test_basic.cpp.o: /home/gonzalo/ProyectoInformatica/Code_test/tests/test_basic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_basic.dir/test_basic.cpp.o"
	cd /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/tests && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_basic.dir/test_basic.cpp.o -c /home/gonzalo/ProyectoInformatica/Code_test/tests/test_basic.cpp

tests/CMakeFiles/test_basic.dir/test_basic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_basic.dir/test_basic.cpp.i"
	cd /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gonzalo/ProyectoInformatica/Code_test/tests/test_basic.cpp > CMakeFiles/test_basic.dir/test_basic.cpp.i

tests/CMakeFiles/test_basic.dir/test_basic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_basic.dir/test_basic.cpp.s"
	cd /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gonzalo/ProyectoInformatica/Code_test/tests/test_basic.cpp -o CMakeFiles/test_basic.dir/test_basic.cpp.s

# Object files for target test_basic
test_basic_OBJECTS = \
"CMakeFiles/test_basic.dir/test_basic.cpp.o"

# External object files for target test_basic
test_basic_EXTERNAL_OBJECTS =

tests/test_basic: tests/CMakeFiles/test_basic.dir/test_basic.cpp.o
tests/test_basic: tests/CMakeFiles/test_basic.dir/build.make
tests/test_basic: lib/libgtest_maind.a
tests/test_basic: libCompuGlobalHyperMegaComponentsLib.a
tests/test_basic: lib/libgtestd.a
tests/test_basic: tests/CMakeFiles/test_basic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_basic"
	cd /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_basic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_basic.dir/build: tests/test_basic

.PHONY : tests/CMakeFiles/test_basic.dir/build

tests/CMakeFiles/test_basic.dir/clean:
	cd /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_basic.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_basic.dir/clean

tests/CMakeFiles/test_basic.dir/depend:
	cd /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gonzalo/ProyectoInformatica/Code_test /home/gonzalo/ProyectoInformatica/Code_test/tests /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/tests /home/gonzalo/ProyectoInformatica/build-Code_test-Desktop-Debug/tests/CMakeFiles/test_basic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_basic.dir/depend

