# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nomap\CLionProjects\LINAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nomap\CLionProjects\LINAL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LINAL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LINAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LINAL.dir/flags.make

CMakeFiles/LINAL.dir/main.cpp.obj: CMakeFiles/LINAL.dir/flags.make
CMakeFiles/LINAL.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nomap\CLionProjects\LINAL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LINAL.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LINAL.dir\main.cpp.obj -c C:\Users\nomap\CLionProjects\LINAL\main.cpp

CMakeFiles/LINAL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LINAL.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nomap\CLionProjects\LINAL\main.cpp > CMakeFiles\LINAL.dir\main.cpp.i

CMakeFiles/LINAL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LINAL.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nomap\CLionProjects\LINAL\main.cpp -o CMakeFiles\LINAL.dir\main.cpp.s

# Object files for target LINAL
LINAL_OBJECTS = \
"CMakeFiles/LINAL.dir/main.cpp.obj"

# External object files for target LINAL
LINAL_EXTERNAL_OBJECTS =

LINAL.exe: CMakeFiles/LINAL.dir/main.cpp.obj
LINAL.exe: CMakeFiles/LINAL.dir/build.make
LINAL.exe: CMakeFiles/LINAL.dir/linklibs.rsp
LINAL.exe: CMakeFiles/LINAL.dir/objects1.rsp
LINAL.exe: CMakeFiles/LINAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nomap\CLionProjects\LINAL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LINAL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LINAL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LINAL.dir/build: LINAL.exe

.PHONY : CMakeFiles/LINAL.dir/build

CMakeFiles/LINAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LINAL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LINAL.dir/clean

CMakeFiles/LINAL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\nomap\CLionProjects\LINAL C:\Users\nomap\CLionProjects\LINAL C:\Users\nomap\CLionProjects\LINAL\cmake-build-debug C:\Users\nomap\CLionProjects\LINAL\cmake-build-debug C:\Users\nomap\CLionProjects\LINAL\cmake-build-debug\CMakeFiles\LINAL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LINAL.dir/depend

