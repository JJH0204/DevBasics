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
include CMakeFiles/ArrayGraph.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ArrayGraph.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ArrayGraph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ArrayGraph.dir/flags.make

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.obj: CMakeFiles/ArrayGraph.dir/flags.make
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.obj: CMakeFiles/ArrayGraph.dir/includes_C.rsp
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.obj: E:/Document/GitHub/DevBasics/source/DSNA/non-Linear/mainGraph.c
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.obj: CMakeFiles/ArrayGraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.obj -MF CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\mainGraph.c.obj.d -o CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\mainGraph.c.obj -c E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\mainGraph.c

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\mainGraph.c > CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\mainGraph.c.i

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\mainGraph.c -o CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\mainGraph.c.s

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.obj: CMakeFiles/ArrayGraph.dir/flags.make
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.obj: CMakeFiles/ArrayGraph.dir/includes_C.rsp
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.obj: E:/Document/GitHub/DevBasics/source/DSNA/non-Linear/includeArrayGraph.c
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.obj: CMakeFiles/ArrayGraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.obj -MF CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\includeArrayGraph.c.obj.d -o CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\includeArrayGraph.c.obj -c E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\includeArrayGraph.c

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\includeArrayGraph.c > CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\includeArrayGraph.c.i

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\includeArrayGraph.c -o CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\includeArrayGraph.c.s

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.obj: CMakeFiles/ArrayGraph.dir/flags.make
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.obj: CMakeFiles/ArrayGraph.dir/includes_C.rsp
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.obj: E:/Document/GitHub/DevBasics/source/DSNA/non-Linear/includeGenericStructure.c
CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.obj: CMakeFiles/ArrayGraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.obj -MF CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\includeGenericStructure.c.obj.d -o CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\includeGenericStructure.c.obj -c E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\includeGenericStructure.c

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\includeGenericStructure.c > CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\includeGenericStructure.c.i

CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Document\GitHub\DevBasics\source\DSNA\non-Linear\includeGenericStructure.c -o CMakeFiles\ArrayGraph.dir\source\DSNA\non-Linear\includeGenericStructure.c.s

# Object files for target ArrayGraph
ArrayGraph_OBJECTS = \
"CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.obj" \
"CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.obj" \
"CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.obj"

# External object files for target ArrayGraph
ArrayGraph_EXTERNAL_OBJECTS =

ArrayGraph.exe: CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/mainGraph.c.obj
ArrayGraph.exe: CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeArrayGraph.c.obj
ArrayGraph.exe: CMakeFiles/ArrayGraph.dir/source/DSNA/non-Linear/includeGenericStructure.c.obj
ArrayGraph.exe: CMakeFiles/ArrayGraph.dir/build.make
ArrayGraph.exe: CMakeFiles/ArrayGraph.dir/linkLibs.rsp
ArrayGraph.exe: CMakeFiles/ArrayGraph.dir/objects1.rsp
ArrayGraph.exe: CMakeFiles/ArrayGraph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ArrayGraph.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ArrayGraph.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ArrayGraph.dir/build: ArrayGraph.exe
.PHONY : CMakeFiles/ArrayGraph.dir/build

CMakeFiles/ArrayGraph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ArrayGraph.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ArrayGraph.dir/clean

CMakeFiles/ArrayGraph.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Document\GitHub\DevBasics E:\Document\GitHub\DevBasics E:\Document\GitHub\DevBasics\build\build_win E:\Document\GitHub\DevBasics\build\build_win E:\Document\GitHub\DevBasics\build\build_win\CMakeFiles\arrayGraph.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ArrayGraph.dir/depend

