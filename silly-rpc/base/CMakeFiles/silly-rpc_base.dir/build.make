# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/lilde90/code/github/silly-rpc/silly-rpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilde90/code/github/silly-rpc/silly-rpc

# Include any dependencies generated for this target.
include base/CMakeFiles/silly-rpc_base.dir/depend.make

# Include the progress variables for this target.
include base/CMakeFiles/silly-rpc_base.dir/progress.make

# Include the compile flags for this target's objects.
include base/CMakeFiles/silly-rpc_base.dir/flags.make

base/CMakeFiles/silly-rpc_base.dir/logging.cc.o: base/CMakeFiles/silly-rpc_base.dir/flags.make
base/CMakeFiles/silly-rpc_base.dir/logging.cc.o: base/logging.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilde90/code/github/silly-rpc/silly-rpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base/CMakeFiles/silly-rpc_base.dir/logging.cc.o"
	cd /home/lilde90/code/github/silly-rpc/silly-rpc/base && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/silly-rpc_base.dir/logging.cc.o -c /home/lilde90/code/github/silly-rpc/silly-rpc/base/logging.cc

base/CMakeFiles/silly-rpc_base.dir/logging.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/silly-rpc_base.dir/logging.cc.i"
	cd /home/lilde90/code/github/silly-rpc/silly-rpc/base && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lilde90/code/github/silly-rpc/silly-rpc/base/logging.cc > CMakeFiles/silly-rpc_base.dir/logging.cc.i

base/CMakeFiles/silly-rpc_base.dir/logging.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/silly-rpc_base.dir/logging.cc.s"
	cd /home/lilde90/code/github/silly-rpc/silly-rpc/base && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lilde90/code/github/silly-rpc/silly-rpc/base/logging.cc -o CMakeFiles/silly-rpc_base.dir/logging.cc.s

base/CMakeFiles/silly-rpc_base.dir/logging.cc.o.requires:

.PHONY : base/CMakeFiles/silly-rpc_base.dir/logging.cc.o.requires

base/CMakeFiles/silly-rpc_base.dir/logging.cc.o.provides: base/CMakeFiles/silly-rpc_base.dir/logging.cc.o.requires
	$(MAKE) -f base/CMakeFiles/silly-rpc_base.dir/build.make base/CMakeFiles/silly-rpc_base.dir/logging.cc.o.provides.build
.PHONY : base/CMakeFiles/silly-rpc_base.dir/logging.cc.o.provides

base/CMakeFiles/silly-rpc_base.dir/logging.cc.o.provides.build: base/CMakeFiles/silly-rpc_base.dir/logging.cc.o


# Object files for target silly-rpc_base
silly__rpc_base_OBJECTS = \
"CMakeFiles/silly-rpc_base.dir/logging.cc.o"

# External object files for target silly-rpc_base
silly__rpc_base_EXTERNAL_OBJECTS =

base/libsilly-rpc_base.a: base/CMakeFiles/silly-rpc_base.dir/logging.cc.o
base/libsilly-rpc_base.a: base/CMakeFiles/silly-rpc_base.dir/build.make
base/libsilly-rpc_base.a: base/CMakeFiles/silly-rpc_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilde90/code/github/silly-rpc/silly-rpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsilly-rpc_base.a"
	cd /home/lilde90/code/github/silly-rpc/silly-rpc/base && $(CMAKE_COMMAND) -P CMakeFiles/silly-rpc_base.dir/cmake_clean_target.cmake
	cd /home/lilde90/code/github/silly-rpc/silly-rpc/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/silly-rpc_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/CMakeFiles/silly-rpc_base.dir/build: base/libsilly-rpc_base.a

.PHONY : base/CMakeFiles/silly-rpc_base.dir/build

base/CMakeFiles/silly-rpc_base.dir/requires: base/CMakeFiles/silly-rpc_base.dir/logging.cc.o.requires

.PHONY : base/CMakeFiles/silly-rpc_base.dir/requires

base/CMakeFiles/silly-rpc_base.dir/clean:
	cd /home/lilde90/code/github/silly-rpc/silly-rpc/base && $(CMAKE_COMMAND) -P CMakeFiles/silly-rpc_base.dir/cmake_clean.cmake
.PHONY : base/CMakeFiles/silly-rpc_base.dir/clean

base/CMakeFiles/silly-rpc_base.dir/depend:
	cd /home/lilde90/code/github/silly-rpc/silly-rpc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilde90/code/github/silly-rpc/silly-rpc /home/lilde90/code/github/silly-rpc/silly-rpc/base /home/lilde90/code/github/silly-rpc/silly-rpc /home/lilde90/code/github/silly-rpc/silly-rpc/base /home/lilde90/code/github/silly-rpc/silly-rpc/base/CMakeFiles/silly-rpc_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/CMakeFiles/silly-rpc_base.dir/depend

