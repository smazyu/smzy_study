# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
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
CMAKE_BINARY_DIR = E:\GitHub\smzy_study\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\smzy.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\smzy.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\smzy.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\smzy.dir\flags.make

CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.obj: CMakeFiles\smzy.dir\flags.make
CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.obj: E:\GitHub\smzy_study\cpp_study\day_25\text1.cpp
CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.obj: CMakeFiles\smzy.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\GitHub\smzy_study\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/smzy.dir/cpp_study/day_25/text1.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.obj.d --working-dir=E:\GitHub\smzy_study\cmake-build-debug --filter-prefix="ע��: �����ļ�:  " -- C:\PROGRA~1\MICROS~3\2022\PROFES~1\VC\Tools\MSVC\1439~1.335\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.obj /FdCMakeFiles\smzy.dir\ /FS -c E:\GitHub\smzy_study\cpp_study\day_25\text1.cpp
<<

CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/smzy.dir/cpp_study/day_25/text1.cpp.i"
	C:\PROGRA~1\MICROS~3\2022\PROFES~1\VC\Tools\MSVC\1439~1.335\bin\Hostx64\x64\cl.exe > CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\GitHub\smzy_study\cpp_study\day_25\text1.cpp
<<

CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/smzy.dir/cpp_study/day_25/text1.cpp.s"
	C:\PROGRA~1\MICROS~3\2022\PROFES~1\VC\Tools\MSVC\1439~1.335\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.s /c E:\GitHub\smzy_study\cpp_study\day_25\text1.cpp
<<

# Object files for target smzy
smzy_OBJECTS = \
"CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.obj"

# External object files for target smzy
smzy_EXTERNAL_OBJECTS =

smzy.exe: CMakeFiles\smzy.dir\cpp_study\day_25\text1.cpp.obj
smzy.exe: CMakeFiles\smzy.dir\build.make
smzy.exe: CMakeFiles\smzy.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\GitHub\smzy_study\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable smzy.exe"
	"E:\Program Files\JetBrains\CLion 2024.1.1\bin\cmake\win\x64\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\smzy.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100226~1.0\x64\mt.exe --manifests -- C:\PROGRA~1\MICROS~3\2022\PROFES~1\VC\Tools\MSVC\1439~1.335\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\smzy.dir\objects1.rsp @<<
 /out:smzy.exe /implib:smzy.lib /pdb:E:\GitHub\smzy_study\cmake-build-debug\smzy.pdb /version:0.0 /machine:x64 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\smzy.dir\build: smzy.exe
.PHONY : CMakeFiles\smzy.dir\build

CMakeFiles\smzy.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\smzy.dir\cmake_clean.cmake
.PHONY : CMakeFiles\smzy.dir\clean

CMakeFiles\smzy.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\GitHub\smzy_study E:\GitHub\smzy_study E:\GitHub\smzy_study\cmake-build-debug E:\GitHub\smzy_study\cmake-build-debug E:\GitHub\smzy_study\cmake-build-debug\CMakeFiles\smzy.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles\smzy.dir\depend

