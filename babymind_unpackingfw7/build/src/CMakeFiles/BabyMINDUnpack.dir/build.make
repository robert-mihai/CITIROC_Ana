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
include src/CMakeFiles/BabyMINDUnpack.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/BabyMINDUnpack.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/BabyMINDUnpack.dir/flags.make

src/CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.o: src/CMakeFiles/BabyMINDUnpack.dir/flags.make
src/CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.o: ../src/MDargumentHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDargumentHandler.cpp

src/CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDargumentHandler.cpp > CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.i

src/CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDargumentHandler.cpp -o CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.s

src/CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.o: src/CMakeFiles/BabyMINDUnpack.dir/flags.make
src/CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.o: ../src/MDdataFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDdataFile.cpp

src/CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDdataFile.cpp > CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.i

src/CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDdataFile.cpp -o CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.s

src/CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.o: src/CMakeFiles/BabyMINDUnpack.dir/flags.make
src/CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.o: ../src/MDdataWordBM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDdataWordBM.cpp

src/CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDdataWordBM.cpp > CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.i

src/CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDdataWordBM.cpp -o CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.s

src/CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.o: src/CMakeFiles/BabyMINDUnpack.dir/flags.make
src/CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.o: ../src/MDexception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDexception.cpp

src/CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDexception.cpp > CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.i

src/CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDexception.cpp -o CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.s

src/CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.o: src/CMakeFiles/BabyMINDUnpack.dir/flags.make
src/CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.o: ../src/MDfragmentBM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDfragmentBM.cpp

src/CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDfragmentBM.cpp > CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.i

src/CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDfragmentBM.cpp -o CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.s

src/CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.o: src/CMakeFiles/BabyMINDUnpack.dir/flags.make
src/CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.o: ../src/MDpartEventBM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.o"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.o -c /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDpartEventBM.cpp

src/CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.i"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDpartEventBM.cpp > CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.i

src/CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.s"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src/MDpartEventBM.cpp -o CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.s

# Object files for target BabyMINDUnpack
BabyMINDUnpack_OBJECTS = \
"CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.o" \
"CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.o" \
"CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.o" \
"CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.o" \
"CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.o" \
"CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.o"

# External object files for target BabyMINDUnpack
BabyMINDUnpack_EXTERNAL_OBJECTS =

../lib/libBabyMINDUnpack.dylib: src/CMakeFiles/BabyMINDUnpack.dir/MDargumentHandler.cpp.o
../lib/libBabyMINDUnpack.dylib: src/CMakeFiles/BabyMINDUnpack.dir/MDdataFile.cpp.o
../lib/libBabyMINDUnpack.dylib: src/CMakeFiles/BabyMINDUnpack.dir/MDdataWordBM.cpp.o
../lib/libBabyMINDUnpack.dylib: src/CMakeFiles/BabyMINDUnpack.dir/MDexception.cpp.o
../lib/libBabyMINDUnpack.dylib: src/CMakeFiles/BabyMINDUnpack.dir/MDfragmentBM.cpp.o
../lib/libBabyMINDUnpack.dylib: src/CMakeFiles/BabyMINDUnpack.dir/MDpartEventBM.cpp.o
../lib/libBabyMINDUnpack.dylib: src/CMakeFiles/BabyMINDUnpack.dir/build.make
../lib/libBabyMINDUnpack.dylib: src/CMakeFiles/BabyMINDUnpack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library ../../lib/libBabyMINDUnpack.dylib"
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BabyMINDUnpack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/BabyMINDUnpack.dir/build: ../lib/libBabyMINDUnpack.dylib

.PHONY : src/CMakeFiles/BabyMINDUnpack.dir/build

src/CMakeFiles/BabyMINDUnpack.dir/clean:
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src && $(CMAKE_COMMAND) -P CMakeFiles/BabyMINDUnpack.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/BabyMINDUnpack.dir/clean

src/CMakeFiles/BabyMINDUnpack.dir/depend:
	cd /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7 /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/src /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src /Users/robertamarinei/Desktop/Year1_PhD/BabyMindElectronics/babymind_unpackingfw7/build/src/CMakeFiles/BabyMINDUnpack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/BabyMINDUnpack.dir/depend
