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
CMAKE_SOURCE_DIR = /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/build

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/main.c.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hello.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hello.dir/main.c.o   -c /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/main.c

CMakeFiles/hello.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/main.c > CMakeFiles/hello.dir/main.c.i

CMakeFiles/hello.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/main.c -o CMakeFiles/hello.dir/main.c.s

CMakeFiles/hello.dir/func.c.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/func.c.o: ../func.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/hello.dir/func.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hello.dir/func.c.o   -c /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/func.c

CMakeFiles/hello.dir/func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello.dir/func.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/func.c > CMakeFiles/hello.dir/func.c.i

CMakeFiles/hello.dir/func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello.dir/func.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/func.c -o CMakeFiles/hello.dir/func.c.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/main.c.o" \
"CMakeFiles/hello.dir/func.c.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

hello: CMakeFiles/hello.dir/main.c.o
hello: CMakeFiles/hello.dir/func.c.o
hello: CMakeFiles/hello.dir/build.make
hello: CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: hello

.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	cd /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/build /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/build /mnt/h/vs_Community/项目管理/练习/cpp速成/速成c++面向对象/cpp面向对象-补充/2024ros/60_cmakelist/build/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello.dir/depend

