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
CMAKE_COMMAND = /snap/cmake/1437/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1437/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/husz/PW/ab12345

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/husz/PW/ab12345/build

# Include any dependencies generated for this target.
include nonrecursive/CMakeFiles/nonrecursive.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include nonrecursive/CMakeFiles/nonrecursive.dir/compiler_depend.make

# Include the progress variables for this target.
include nonrecursive/CMakeFiles/nonrecursive.dir/progress.make

# Include the compile flags for this target's objects.
include nonrecursive/CMakeFiles/nonrecursive.dir/flags.make

nonrecursive/CMakeFiles/nonrecursive.dir/codegen:
.PHONY : nonrecursive/CMakeFiles/nonrecursive.dir/codegen

nonrecursive/CMakeFiles/nonrecursive.dir/main.c.o: nonrecursive/CMakeFiles/nonrecursive.dir/flags.make
nonrecursive/CMakeFiles/nonrecursive.dir/main.c.o: /home/husz/PW/ab12345/nonrecursive/main.c
nonrecursive/CMakeFiles/nonrecursive.dir/main.c.o: nonrecursive/CMakeFiles/nonrecursive.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/husz/PW/ab12345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object nonrecursive/CMakeFiles/nonrecursive.dir/main.c.o"
	cd /home/husz/PW/ab12345/build/nonrecursive && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT nonrecursive/CMakeFiles/nonrecursive.dir/main.c.o -MF CMakeFiles/nonrecursive.dir/main.c.o.d -o CMakeFiles/nonrecursive.dir/main.c.o -c /home/husz/PW/ab12345/nonrecursive/main.c

nonrecursive/CMakeFiles/nonrecursive.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/nonrecursive.dir/main.c.i"
	cd /home/husz/PW/ab12345/build/nonrecursive && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/husz/PW/ab12345/nonrecursive/main.c > CMakeFiles/nonrecursive.dir/main.c.i

nonrecursive/CMakeFiles/nonrecursive.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/nonrecursive.dir/main.c.s"
	cd /home/husz/PW/ab12345/build/nonrecursive && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/husz/PW/ab12345/nonrecursive/main.c -o CMakeFiles/nonrecursive.dir/main.c.s

# Object files for target nonrecursive
nonrecursive_OBJECTS = \
"CMakeFiles/nonrecursive.dir/main.c.o"

# External object files for target nonrecursive
nonrecursive_EXTERNAL_OBJECTS =

nonrecursive/nonrecursive: nonrecursive/CMakeFiles/nonrecursive.dir/main.c.o
nonrecursive/nonrecursive: nonrecursive/CMakeFiles/nonrecursive.dir/build.make
nonrecursive/nonrecursive: common/libio.a
nonrecursive/nonrecursive: common/liberr.a
nonrecursive/nonrecursive: nonrecursive/CMakeFiles/nonrecursive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/husz/PW/ab12345/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable nonrecursive"
	cd /home/husz/PW/ab12345/build/nonrecursive && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nonrecursive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
nonrecursive/CMakeFiles/nonrecursive.dir/build: nonrecursive/nonrecursive
.PHONY : nonrecursive/CMakeFiles/nonrecursive.dir/build

nonrecursive/CMakeFiles/nonrecursive.dir/clean:
	cd /home/husz/PW/ab12345/build/nonrecursive && $(CMAKE_COMMAND) -P CMakeFiles/nonrecursive.dir/cmake_clean.cmake
.PHONY : nonrecursive/CMakeFiles/nonrecursive.dir/clean

nonrecursive/CMakeFiles/nonrecursive.dir/depend:
	cd /home/husz/PW/ab12345/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/husz/PW/ab12345 /home/husz/PW/ab12345/nonrecursive /home/husz/PW/ab12345/build /home/husz/PW/ab12345/build/nonrecursive /home/husz/PW/ab12345/build/nonrecursive/CMakeFiles/nonrecursive.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : nonrecursive/CMakeFiles/nonrecursive.dir/depend

