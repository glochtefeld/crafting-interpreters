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
CMAKE_SOURCE_DIR = /home/lochga01/Projects/crafting-interpreters/clox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lochga01/Projects/crafting-interpreters/clox/build

# Include any dependencies generated for this target.
include CMakeFiles/value.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/value.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/value.dir/flags.make

CMakeFiles/value.dir/src/value.c.o: CMakeFiles/value.dir/flags.make
CMakeFiles/value.dir/src/value.c.o: ../src/value.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lochga01/Projects/crafting-interpreters/clox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/value.dir/src/value.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/value.dir/src/value.c.o   -c /home/lochga01/Projects/crafting-interpreters/clox/src/value.c

CMakeFiles/value.dir/src/value.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/value.dir/src/value.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lochga01/Projects/crafting-interpreters/clox/src/value.c > CMakeFiles/value.dir/src/value.c.i

CMakeFiles/value.dir/src/value.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/value.dir/src/value.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lochga01/Projects/crafting-interpreters/clox/src/value.c -o CMakeFiles/value.dir/src/value.c.s

# Object files for target value
value_OBJECTS = \
"CMakeFiles/value.dir/src/value.c.o"

# External object files for target value
value_EXTERNAL_OBJECTS =

libvalue.a: CMakeFiles/value.dir/src/value.c.o
libvalue.a: CMakeFiles/value.dir/build.make
libvalue.a: CMakeFiles/value.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lochga01/Projects/crafting-interpreters/clox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libvalue.a"
	$(CMAKE_COMMAND) -P CMakeFiles/value.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/value.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/value.dir/build: libvalue.a

.PHONY : CMakeFiles/value.dir/build

CMakeFiles/value.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/value.dir/cmake_clean.cmake
.PHONY : CMakeFiles/value.dir/clean

CMakeFiles/value.dir/depend:
	cd /home/lochga01/Projects/crafting-interpreters/clox/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lochga01/Projects/crafting-interpreters/clox /home/lochga01/Projects/crafting-interpreters/clox /home/lochga01/Projects/crafting-interpreters/clox/build /home/lochga01/Projects/crafting-interpreters/clox/build /home/lochga01/Projects/crafting-interpreters/clox/build/CMakeFiles/value.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/value.dir/depend
