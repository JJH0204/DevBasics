# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Document\GitHub\DevBasics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Document\GitHub\DevBasics\build\build_win

# Include any dependencies generated for this target.
include CMakeFiles/algorithmTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/algorithmTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithmTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithmTest.dir/flags.make

CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.obj: CMakeFiles/algorithmTest.dir/flags.make
CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.obj: CMakeFiles/algorithmTest.dir/includes_C.rsp
CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.obj: E:/Document/GitHub/DevBasics/source/DSNA/Algorithm/mainBsearch.c
CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.obj: CMakeFiles/algorithmTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.obj -MF CMakeFiles\algorithmTest.dir\source\DSNA\Algorithm\mainBsearch.c.obj.d -o CMakeFiles\algorithmTest.dir\source\DSNA\Algorithm\mainBsearch.c.obj -c E:\Document\GitHub\DevBasics\source\DSNA\Algorithm\mainBsearch.c

CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Document\GitHub\DevBasics\source\DSNA\Algorithm\mainBsearch.c > CMakeFiles\algorithmTest.dir\source\DSNA\Algorithm\mainBsearch.c.i

CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Document\GitHub\DevBasics\source\DSNA\Algorithm\mainBsearch.c -o CMakeFiles\algorithmTest.dir\source\DSNA\Algorithm\mainBsearch.c.s

# Object files for target algorithmTest
algorithmTest_OBJECTS = \
"CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.obj"

# External object files for target algorithmTest
algorithmTest_EXTERNAL_OBJECTS =

algorithmTest.exe: CMakeFiles/algorithmTest.dir/source/DSNA/Algorithm/mainBsearch.c.obj
algorithmTest.exe: CMakeFiles/algorithmTest.dir/build.make
algorithmTest.exe: CMakeFiles/algorithmTest.dir/linkLibs.rsp
algorithmTest.exe: CMakeFiles/algorithmTest.dir/objects1.rsp
algorithmTest.exe: CMakeFiles/algorithmTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable algorithmTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorithmTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithmTest.dir/build: algorithmTest.exe
.PHONY : CMakeFiles/algorithmTest.dir/build

CMakeFiles/algorithmTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorithmTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algorithmTest.dir/clean

CMakeFiles/algorithmTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Document\GitHub\DevBasics E:\Document\GitHub\DevBasics E:\Document\GitHub\DevBasics\build\build_win E:\Document\GitHub\DevBasics\build\build_win E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles\algorithmTest.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/algorithmTest.dir/depend

