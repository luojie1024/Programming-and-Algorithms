# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/luojie/下载/clion-2017.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/luojie/下载/clion-2017.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/StringLastWrod.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StringLastWrod.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StringLastWrod.dir/flags.make

CMakeFiles/StringLastWrod.dir/main.cpp.o: CMakeFiles/StringLastWrod.dir/flags.make
CMakeFiles/StringLastWrod.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StringLastWrod.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StringLastWrod.dir/main.cpp.o -c "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/main.cpp"

CMakeFiles/StringLastWrod.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringLastWrod.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/main.cpp" > CMakeFiles/StringLastWrod.dir/main.cpp.i

CMakeFiles/StringLastWrod.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringLastWrod.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/main.cpp" -o CMakeFiles/StringLastWrod.dir/main.cpp.s

CMakeFiles/StringLastWrod.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/StringLastWrod.dir/main.cpp.o.requires

CMakeFiles/StringLastWrod.dir/main.cpp.o.provides: CMakeFiles/StringLastWrod.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/StringLastWrod.dir/build.make CMakeFiles/StringLastWrod.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/StringLastWrod.dir/main.cpp.o.provides

CMakeFiles/StringLastWrod.dir/main.cpp.o.provides.build: CMakeFiles/StringLastWrod.dir/main.cpp.o


# Object files for target StringLastWrod
StringLastWrod_OBJECTS = \
"CMakeFiles/StringLastWrod.dir/main.cpp.o"

# External object files for target StringLastWrod
StringLastWrod_EXTERNAL_OBJECTS =

StringLastWrod: CMakeFiles/StringLastWrod.dir/main.cpp.o
StringLastWrod: CMakeFiles/StringLastWrod.dir/build.make
StringLastWrod: CMakeFiles/StringLastWrod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StringLastWrod"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StringLastWrod.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StringLastWrod.dir/build: StringLastWrod

.PHONY : CMakeFiles/StringLastWrod.dir/build

CMakeFiles/StringLastWrod.dir/requires: CMakeFiles/StringLastWrod.dir/main.cpp.o.requires

.PHONY : CMakeFiles/StringLastWrod.dir/requires

CMakeFiles/StringLastWrod.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StringLastWrod.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StringLastWrod.dir/clean

CMakeFiles/StringLastWrod.dir/depend:
	cd "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod" "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod" "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/cmake-build-debug" "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/cmake-build-debug" "/home/luojie/CLionProjects/Programming and Algorithms/nowcoder/huawei/StringLastWrod/cmake-build-debug/CMakeFiles/StringLastWrod.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/StringLastWrod.dir/depend

