# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = C:\Users\julia\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3739.54\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\julia\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3739.54\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\julia\CLionProjects\Cen_3031_Minigames

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\julia\CLionProjects\Cen_3031_Minigames\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Cen_3031_Minigames.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Cen_3031_Minigames.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Cen_3031_Minigames.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cen_3031_Minigames.dir/flags.make

CMakeFiles/Cen_3031_Minigames.dir/main.cpp.obj: CMakeFiles/Cen_3031_Minigames.dir/flags.make
CMakeFiles/Cen_3031_Minigames.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Cen_3031_Minigames.dir/main.cpp.obj: CMakeFiles/Cen_3031_Minigames.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\julia\CLionProjects\Cen_3031_Minigames\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cen_3031_Minigames.dir/main.cpp.obj"
	C:\Users\julia\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3739.54\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cen_3031_Minigames.dir/main.cpp.obj -MF CMakeFiles\Cen_3031_Minigames.dir\main.cpp.obj.d -o CMakeFiles\Cen_3031_Minigames.dir\main.cpp.obj -c C:\Users\julia\CLionProjects\Cen_3031_Minigames\main.cpp

CMakeFiles/Cen_3031_Minigames.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cen_3031_Minigames.dir/main.cpp.i"
	C:\Users\julia\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3739.54\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\julia\CLionProjects\Cen_3031_Minigames\main.cpp > CMakeFiles\Cen_3031_Minigames.dir\main.cpp.i

CMakeFiles/Cen_3031_Minigames.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cen_3031_Minigames.dir/main.cpp.s"
	C:\Users\julia\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.3739.54\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\julia\CLionProjects\Cen_3031_Minigames\main.cpp -o CMakeFiles\Cen_3031_Minigames.dir\main.cpp.s

# Object files for target Cen_3031_Minigames
Cen_3031_Minigames_OBJECTS = \
"CMakeFiles/Cen_3031_Minigames.dir/main.cpp.obj"

# External object files for target Cen_3031_Minigames
Cen_3031_Minigames_EXTERNAL_OBJECTS =

Cen_3031_Minigames.exe: CMakeFiles/Cen_3031_Minigames.dir/main.cpp.obj
Cen_3031_Minigames.exe: CMakeFiles/Cen_3031_Minigames.dir/build.make
Cen_3031_Minigames.exe: CMakeFiles/Cen_3031_Minigames.dir/linklibs.rsp
Cen_3031_Minigames.exe: CMakeFiles/Cen_3031_Minigames.dir/objects1.rsp
Cen_3031_Minigames.exe: CMakeFiles/Cen_3031_Minigames.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\julia\CLionProjects\Cen_3031_Minigames\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Cen_3031_Minigames.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cen_3031_Minigames.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cen_3031_Minigames.dir/build: Cen_3031_Minigames.exe
.PHONY : CMakeFiles/Cen_3031_Minigames.dir/build

CMakeFiles/Cen_3031_Minigames.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cen_3031_Minigames.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cen_3031_Minigames.dir/clean

CMakeFiles/Cen_3031_Minigames.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\julia\CLionProjects\Cen_3031_Minigames C:\Users\julia\CLionProjects\Cen_3031_Minigames C:\Users\julia\CLionProjects\Cen_3031_Minigames\cmake-build-debug C:\Users\julia\CLionProjects\Cen_3031_Minigames\cmake-build-debug C:\Users\julia\CLionProjects\Cen_3031_Minigames\cmake-build-debug\CMakeFiles\Cen_3031_Minigames.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cen_3031_Minigames.dir/depend

