# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/build"

# Include any dependencies generated for this target.
include CMakeFiles/CppRayTracer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CppRayTracer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CppRayTracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CppRayTracer.dir/flags.make

CMakeFiles/CppRayTracer.dir/src/main.cc.o: CMakeFiles/CppRayTracer.dir/flags.make
CMakeFiles/CppRayTracer.dir/src/main.cc.o: /Users/sibgh/Desktop/Graphics\ Projects/cpp-ray-tracer/src/main.cc
CMakeFiles/CppRayTracer.dir/src/main.cc.o: CMakeFiles/CppRayTracer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CppRayTracer.dir/src/main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CppRayTracer.dir/src/main.cc.o -MF CMakeFiles/CppRayTracer.dir/src/main.cc.o.d -o CMakeFiles/CppRayTracer.dir/src/main.cc.o -c "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/src/main.cc"

CMakeFiles/CppRayTracer.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CppRayTracer.dir/src/main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/src/main.cc" > CMakeFiles/CppRayTracer.dir/src/main.cc.i

CMakeFiles/CppRayTracer.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CppRayTracer.dir/src/main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/src/main.cc" -o CMakeFiles/CppRayTracer.dir/src/main.cc.s

# Object files for target CppRayTracer
CppRayTracer_OBJECTS = \
"CMakeFiles/CppRayTracer.dir/src/main.cc.o"

# External object files for target CppRayTracer
CppRayTracer_EXTERNAL_OBJECTS =

CppRayTracer: CMakeFiles/CppRayTracer.dir/src/main.cc.o
CppRayTracer: CMakeFiles/CppRayTracer.dir/build.make
CppRayTracer: CMakeFiles/CppRayTracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CppRayTracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CppRayTracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CppRayTracer.dir/build: CppRayTracer
.PHONY : CMakeFiles/CppRayTracer.dir/build

CMakeFiles/CppRayTracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CppRayTracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CppRayTracer.dir/clean

CMakeFiles/CppRayTracer.dir/depend:
	cd "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer" "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer" "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/build" "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/build" "/Users/sibgh/Desktop/Graphics Projects/cpp-ray-tracer/build/CMakeFiles/CppRayTracer.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/CppRayTracer.dir/depend
