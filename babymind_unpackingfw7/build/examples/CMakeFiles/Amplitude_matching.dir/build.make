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
include examples/CMakeFiles/Amplitude_matching.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/Amplitude_matching.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/Amplitude_matching.dir/flags.make

examples/CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.o: examples/CMakeFiles/Amplitude_matching.dir/flags.make
examples/CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.o: ../examples/BabyMIND_ToT_Amplitude_matching.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/BabyMIND_ToT_Amplitude_matching.cpp

examples/CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/BabyMIND_ToT_Amplitude_matching.cpp > CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.i

examples/CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/BabyMIND_ToT_Amplitude_matching.cpp -o CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.s

# Object files for target Amplitude_matching
Amplitude_matching_OBJECTS = \
"CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.o"

# External object files for target Amplitude_matching
Amplitude_matching_EXTERNAL_OBJECTS =

../bin/Amplitude_matching: examples/CMakeFiles/Amplitude_matching.dir/BabyMIND_ToT_Amplitude_matching.cpp.o
../bin/Amplitude_matching: examples/CMakeFiles/Amplitude_matching.dir/build.make
../bin/Amplitude_matching: ../lib/libBabyMINDUnpack.dylib
../bin/Amplitude_matching: examples/CMakeFiles/Amplitude_matching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/Amplitude_matching"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Amplitude_matching.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/Amplitude_matching.dir/build: ../bin/Amplitude_matching

.PHONY : examples/CMakeFiles/Amplitude_matching.dir/build

examples/CMakeFiles/Amplitude_matching.dir/clean:
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/Amplitude_matching.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/Amplitude_matching.dir/clean

examples/CMakeFiles/Amplitude_matching.dir/depend:
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7 /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples/CMakeFiles/Amplitude_matching.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/Amplitude_matching.dir/depend

