# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\github\katas\katas\CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\github\katas\katas\CPP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPP.dir/flags.make

CMakeFiles/CPP.dir/main.cpp.obj: CMakeFiles/CPP.dir/flags.make
CMakeFiles/CPP.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\katas\katas\CPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPP.dir/main.cpp.obj"
	D:\TDM-GCC-64\bin\c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CPP.dir\main.cpp.obj -c D:\github\katas\katas\CPP\main.cpp

CMakeFiles/CPP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP.dir/main.cpp.i"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\katas\katas\CPP\main.cpp > CMakeFiles\CPP.dir\main.cpp.i

CMakeFiles/CPP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP.dir/main.cpp.s"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\katas\katas\CPP\main.cpp -o CMakeFiles\CPP.dir\main.cpp.s

CMakeFiles/CPP.dir/DirectionsReduction.cpp.obj: CMakeFiles/CPP.dir/flags.make
CMakeFiles/CPP.dir/DirectionsReduction.cpp.obj: ../DirectionsReduction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\katas\katas\CPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPP.dir/DirectionsReduction.cpp.obj"
	D:\TDM-GCC-64\bin\c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CPP.dir\DirectionsReduction.cpp.obj -c D:\github\katas\katas\CPP\DirectionsReduction.cpp

CMakeFiles/CPP.dir/DirectionsReduction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP.dir/DirectionsReduction.cpp.i"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\katas\katas\CPP\DirectionsReduction.cpp > CMakeFiles\CPP.dir\DirectionsReduction.cpp.i

CMakeFiles/CPP.dir/DirectionsReduction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP.dir/DirectionsReduction.cpp.s"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\katas\katas\CPP\DirectionsReduction.cpp -o CMakeFiles\CPP.dir\DirectionsReduction.cpp.s

CMakeFiles/CPP.dir/Valid_Braces.cpp.obj: CMakeFiles/CPP.dir/flags.make
CMakeFiles/CPP.dir/Valid_Braces.cpp.obj: ../Valid\ Braces.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\katas\katas\CPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPP.dir/Valid_Braces.cpp.obj"
	D:\TDM-GCC-64\bin\c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CPP.dir\Valid_Braces.cpp.obj -c "D:\github\katas\katas\CPP\Valid Braces.cpp"

CMakeFiles/CPP.dir/Valid_Braces.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP.dir/Valid_Braces.cpp.i"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\github\katas\katas\CPP\Valid Braces.cpp" > CMakeFiles\CPP.dir\Valid_Braces.cpp.i

CMakeFiles/CPP.dir/Valid_Braces.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP.dir/Valid_Braces.cpp.s"
	D:\TDM-GCC-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\github\katas\katas\CPP\Valid Braces.cpp" -o CMakeFiles\CPP.dir\Valid_Braces.cpp.s

# Object files for target CPP
CPP_OBJECTS = \
"CMakeFiles/CPP.dir/main.cpp.obj" \
"CMakeFiles/CPP.dir/DirectionsReduction.cpp.obj" \
"CMakeFiles/CPP.dir/Valid_Braces.cpp.obj"

# External object files for target CPP
CPP_EXTERNAL_OBJECTS =

CPP.exe: CMakeFiles/CPP.dir/main.cpp.obj
CPP.exe: CMakeFiles/CPP.dir/DirectionsReduction.cpp.obj
CPP.exe: CMakeFiles/CPP.dir/Valid_Braces.cpp.obj
CPP.exe: CMakeFiles/CPP.dir/build.make
CPP.exe: CMakeFiles/CPP.dir/linklibs.rsp
CPP.exe: CMakeFiles/CPP.dir/objects1.rsp
CPP.exe: CMakeFiles/CPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\katas\katas\CPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CPP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CPP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPP.dir/build: CPP.exe

.PHONY : CMakeFiles/CPP.dir/build

CMakeFiles/CPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CPP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CPP.dir/clean

CMakeFiles/CPP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\katas\katas\CPP D:\github\katas\katas\CPP D:\github\katas\katas\CPP\cmake-build-debug D:\github\katas\katas\CPP\cmake-build-debug D:\github\katas\katas\CPP\cmake-build-debug\CMakeFiles\CPP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPP.dir/depend

