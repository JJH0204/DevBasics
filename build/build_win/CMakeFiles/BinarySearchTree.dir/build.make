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
include CMakeFiles/BinarySearchTree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BinarySearchTree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BinarySearchTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BinarySearchTree.dir/flags.make

CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.obj: CMakeFiles/BinarySearchTree.dir/flags.make
CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.obj: CMakeFiles/BinarySearchTree.dir/includes_C.rsp
CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.obj: E:/Document/GitHub/DevBasics/source/DSNA/Search/mainBinSearchTree.c
CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.obj: CMakeFiles/BinarySearchTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.obj -MF CMakeFiles\BinarySearchTree.dir\source\DSNA\Search\mainBinSearchTree.c.obj.d -o CMakeFiles\BinarySearchTree.dir\source\DSNA\Search\mainBinSearchTree.c.obj -c E:\Document\GitHub\DevBasics\source\DSNA\Search\mainBinSearchTree.c

CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Document\GitHub\DevBasics\source\DSNA\Search\mainBinSearchTree.c > CMakeFiles\BinarySearchTree.dir\source\DSNA\Search\mainBinSearchTree.c.i

CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Document\GitHub\DevBasics\source\DSNA\Search\mainBinSearchTree.c -o CMakeFiles\BinarySearchTree.dir\source\DSNA\Search\mainBinSearchTree.c.s

# Object files for target BinarySearchTree
BinarySearchTree_OBJECTS = \
"CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.obj"

# External object files for target BinarySearchTree
BinarySearchTree_EXTERNAL_OBJECTS =

BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/source/DSNA/Search/mainBinSearchTree.c.obj
BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/build.make
BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/linkLibs.rsp
BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/objects1.rsp
BinarySearchTree.exe: CMakeFiles/BinarySearchTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BinarySearchTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BinarySearchTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BinarySearchTree.dir/build: BinarySearchTree.exe
.PHONY : CMakeFiles/BinarySearchTree.dir/build

CMakeFiles/BinarySearchTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BinarySearchTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BinarySearchTree.dir/clean

CMakeFiles/BinarySearchTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Document\GitHub\DevBasics E:\Document\GitHub\DevBasics E:\Document\GitHub\DevBasics\build\build_win E:\Document\GitHub\DevBasics\build\build_win E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles\BinarySearchTree.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/BinarySearchTree.dir/depend

