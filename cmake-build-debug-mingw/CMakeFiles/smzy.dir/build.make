# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2024.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2024.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\GitHub\smzy_study

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\GitHub\smzy_study\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/smzy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/smzy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/smzy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/smzy.dir/flags.make

CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.obj: CMakeFiles/smzy.dir/flags.make
CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.obj: CMakeFiles/smzy.dir/includes_C.rsp
CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.obj: E:/GitHub/smzy_study/DSStudy/sort/QuickSort.c
CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.obj: CMakeFiles/smzy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\GitHub\smzy_study\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.obj"
	"E:\Program Files\JetBrains\CLion 2024.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.obj -MF CMakeFiles\smzy.dir\DSStudy\sort\QuickSort.c.obj.d -o CMakeFiles\smzy.dir\DSStudy\sort\QuickSort.c.obj -c E:\GitHub\smzy_study\DSStudy\sort\QuickSort.c

CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.i"
	"E:\Program Files\JetBrains\CLion 2024.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\GitHub\smzy_study\DSStudy\sort\QuickSort.c > CMakeFiles\smzy.dir\DSStudy\sort\QuickSort.c.i

CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.s"
	"E:\Program Files\JetBrains\CLion 2024.1.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\GitHub\smzy_study\DSStudy\sort\QuickSort.c -o CMakeFiles\smzy.dir\DSStudy\sort\QuickSort.c.s

# Object files for target smzy
smzy_OBJECTS = \
"CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.obj"

# External object files for target smzy
smzy_EXTERNAL_OBJECTS =

smzy.exe: CMakeFiles/smzy.dir/DSStudy/sort/QuickSort.c.obj
smzy.exe: CMakeFiles/smzy.dir/build.make
smzy.exe: CMakeFiles/smzy.dir/linkLibs.rsp
smzy.exe: CMakeFiles/smzy.dir/objects1.rsp
smzy.exe: CMakeFiles/smzy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\GitHub\smzy_study\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable smzy.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\smzy.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/smzy.dir/build: smzy.exe
.PHONY : CMakeFiles/smzy.dir/build

CMakeFiles/smzy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\smzy.dir\cmake_clean.cmake
.PHONY : CMakeFiles/smzy.dir/clean

CMakeFiles/smzy.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GitHub\smzy_study E:\GitHub\smzy_study E:\GitHub\smzy_study\cmake-build-debug-mingw E:\GitHub\smzy_study\cmake-build-debug-mingw E:\GitHub\smzy_study\cmake-build-debug-mingw\CMakeFiles\smzy.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/smzy.dir/depend

