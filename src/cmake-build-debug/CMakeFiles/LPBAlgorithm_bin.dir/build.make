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
CMAKE_SOURCE_DIR = /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LPBAlgorithm_bin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LPBAlgorithm_bin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LPBAlgorithm_bin.dir/flags.make

CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.o: CMakeFiles/LPBAlgorithm_bin.dir/flags.make
CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.o -c /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/main.cpp

CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/main.cpp > CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.i

CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/main.cpp -o CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.s

CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.o: CMakeFiles/LPBAlgorithm_bin.dir/flags.make
CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.o: ../mytools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.o -c /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/mytools.cpp

CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/mytools.cpp > CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.i

CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/mytools.cpp -o CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.s

# Object files for target LPBAlgorithm_bin
LPBAlgorithm_bin_OBJECTS = \
"CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.o" \
"CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.o"

# External object files for target LPBAlgorithm_bin
LPBAlgorithm_bin_EXTERNAL_OBJECTS =

LPBAlgorithm_bin: CMakeFiles/LPBAlgorithm_bin.dir/main.cpp.o
LPBAlgorithm_bin: CMakeFiles/LPBAlgorithm_bin.dir/mytools.cpp.o
LPBAlgorithm_bin: CMakeFiles/LPBAlgorithm_bin.dir/build.make
LPBAlgorithm_bin: imgui/libimgui.a
LPBAlgorithm_bin: glfw/src/libglfw3.a
LPBAlgorithm_bin: glad/libglad.a
LPBAlgorithm_bin: CMakeFiles/LPBAlgorithm_bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LPBAlgorithm_bin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LPBAlgorithm_bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LPBAlgorithm_bin.dir/build: LPBAlgorithm_bin

.PHONY : CMakeFiles/LPBAlgorithm_bin.dir/build

CMakeFiles/LPBAlgorithm_bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LPBAlgorithm_bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LPBAlgorithm_bin.dir/clean

CMakeFiles/LPBAlgorithm_bin.dir/depend:
	cd /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/cmake-build-debug /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/cmake-build-debug /Users/silviojin/compM080-compGV18-2019/courseworks/LPB/src/cmake-build-debug/CMakeFiles/LPBAlgorithm_bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LPBAlgorithm_bin.dir/depend

