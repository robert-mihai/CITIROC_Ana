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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/LG_vs_ToT_calib.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/LG_vs_ToT_calib.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/LG_vs_ToT_calib.dir/flags.make

examples/CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.o: examples/CMakeFiles/LG_vs_ToT_calib.dir/flags.make
examples/CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.o: ../examples/LG_vs_ToT_calib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/LG_vs_ToT_calib.cpp

examples/CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/LG_vs_ToT_calib.cpp > CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.i

examples/CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/LG_vs_ToT_calib.cpp -o CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.s

# Object files for target LG_vs_ToT_calib
LG_vs_ToT_calib_OBJECTS = \
"CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.o"

# External object files for target LG_vs_ToT_calib
LG_vs_ToT_calib_EXTERNAL_OBJECTS =

../bin/LG_vs_ToT_calib: examples/CMakeFiles/LG_vs_ToT_calib.dir/LG_vs_ToT_calib.cpp.o
../bin/LG_vs_ToT_calib: examples/CMakeFiles/LG_vs_ToT_calib.dir/build.make
../bin/LG_vs_ToT_calib: ../lib/libBabyMINDUnpack.dylib
../bin/LG_vs_ToT_calib: examples/CMakeFiles/LG_vs_ToT_calib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/LG_vs_ToT_calib"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LG_vs_ToT_calib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/LG_vs_ToT_calib.dir/build: ../bin/LG_vs_ToT_calib

.PHONY : examples/CMakeFiles/LG_vs_ToT_calib.dir/build

examples/CMakeFiles/LG_vs_ToT_calib.dir/clean:
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/LG_vs_ToT_calib.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/LG_vs_ToT_calib.dir/clean

examples/CMakeFiles/LG_vs_ToT_calib.dir/depend:
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7 /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples/CMakeFiles/LG_vs_ToT_calib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/LG_vs_ToT_calib.dir/depend

