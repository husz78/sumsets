# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /snap/cmake/1435/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1435/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/husz/PW/ab12345

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/husz/PW/ab12345/build

# Include any dependencies generated for this target.
include nonrecursive/CMakeFiles/stack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include nonrecursive/CMakeFiles/stack.dir/compiler_depend.make

# Include the progress variables for this target.
include nonrecursive/CMakeFiles/stack.dir/progress.make

# Include the compile flags for this target's objects.
include nonrecursive/CMakeFiles/stack.dir/flags.make

nonrecursive/CMakeFiles/stack.dir/codegen:
.PHONY : nonrecursive/CMakeFiles/stack.dir/codegen

nonrecursive/CMakeFiles/stack.dir/stack.c.o: nonrecursive/CMakeFiles/stack.dir/flags.make
nonrecursive/CMakeFiles/stack.dir/stack.c.o: /home/husz/PW/ab12345/nonrecursive/stack.c
nonrecursive/CMakeFiles/stack.dir/stack.c.o: nonrecursive/CMakeFiles/stack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/husz/PW/ab12345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object nonrecursive/CMakeFiles/stack.dir/stack.c.o"
	cd /home/husz/PW/ab12345/build/nonrecursive && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT nonrecursive/CMakeFiles/stack.dir/stack.c.o -MF CMakeFiles/stack.dir/stack.c.o.d -o CMakeFiles/stack.dir/stack.c.o -c /home/husz/PW/ab12345/nonrecursive/stack.c

nonrecursive/CMakeFiles/stack.dir/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/stack.dir/stack.c.i"
	cd /home/husz/PW/ab12345/build/nonrecursive && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/husz/PW/ab12345/nonrecursive/stack.c > CMakeFiles/stack.dir/stack.c.i

nonrecursive/CMakeFiles/stack.dir/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/stack.dir/stack.c.s"
	cd /home/husz/PW/ab12345/build/nonrecursive && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/husz/PW/ab12345/nonrecursive/stack.c -o CMakeFiles/stack.dir/stack.c.s

# Object files for target stack
stack_OBJECTS = \
"CMakeFiles/stack.dir/stack.c.o"

# External object files for target stack
stack_EXTERNAL_OBJECTS =

nonrecursive/libstack.a: nonrecursive/CMakeFiles/stack.dir/stack.c.o
nonrecursive/libstack.a: nonrecursive/CMakeFiles/stack.dir/build.make
nonrecursive/libstack.a: nonrecursive/CMakeFiles/stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/husz/PW/ab12345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libstack.a"
	cd /home/husz/PW/ab12345/build/nonrecursive && $(CMAKE_COMMAND) -P CMakeFiles/stack.dir/cmake_clean_target.cmake
	cd /home/husz/PW/ab12345/build/nonrecursive && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
nonrecursive/CMakeFiles/stack.dir/build: nonrecursive/libstack.a
.PHONY : nonrecursive/CMakeFiles/stack.dir/build

nonrecursive/CMakeFiles/stack.dir/clean:
	cd /home/husz/PW/ab12345/build/nonrecursive && $(CMAKE_COMMAND) -P CMakeFiles/stack.dir/cmake_clean.cmake
.PHONY : nonrecursive/CMakeFiles/stack.dir/clean

nonrecursive/CMakeFiles/stack.dir/depend:
	cd /home/husz/PW/ab12345/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/husz/PW/ab12345 /home/husz/PW/ab12345/nonrecursive /home/husz/PW/ab12345/build /home/husz/PW/ab12345/build/nonrecursive /home/husz/PW/ab12345/build/nonrecursive/CMakeFiles/stack.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : nonrecursive/CMakeFiles/stack.dir/depend
