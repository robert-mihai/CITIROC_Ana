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
include examples/CMakeFiles/HG_reconstructed.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/HG_reconstructed.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/HG_reconstructed.dir/flags.make

examples/CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.o: examples/CMakeFiles/HG_reconstructed.dir/flags.make
examples/CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.o: ../examples/HG_reconstructed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/HG_reconstructed.cpp

examples/CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/HG_reconstructed.cpp > CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.i

examples/CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples/HG_reconstructed.cpp -o CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.s

# Object files for target HG_reconstructed
HG_reconstructed_OBJECTS = \
"CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.o"

# External object files for target HG_reconstructed
HG_reconstructed_EXTERNAL_OBJECTS =

../bin/HG_reconstructed: examples/CMakeFiles/HG_reconstructed.dir/HG_reconstructed.cpp.o
../bin/HG_reconstructed: examples/CMakeFiles/HG_reconstructed.dir/build.make
../bin/HG_reconstructed: ../lib/libBabyMINDUnpack.dylib
../bin/HG_reconstructed: examples/CMakeFiles/HG_reconstructed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/HG_reconstructed"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HG_reconstructed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/HG_reconstructed.dir/build: ../bin/HG_reconstructed

.PHONY : examples/CMakeFiles/HG_reconstructed.dir/build

examples/CMakeFiles/HG_reconstructed.dir/clean:
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/HG_reconstructed.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/HG_reconstructed.dir/clean

examples/CMakeFiles/HG_reconstructed.dir/depend:
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7 /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/examples /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/examples/CMakeFiles/HG_reconstructed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/HG_reconstructed.dir/depend
