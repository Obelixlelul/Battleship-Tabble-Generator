# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build"

# Include any dependencies generated for this target.
include CMakeFiles/bpg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bpg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bpg.dir/flags.make

CMakeFiles/bpg.dir/src/MainVerification.cpp.o: CMakeFiles/bpg.dir/flags.make
CMakeFiles/bpg.dir/src/MainVerification.cpp.o: ../src/MainVerification.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bpg.dir/src/MainVerification.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bpg.dir/src/MainVerification.cpp.o -c "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/MainVerification.cpp"

CMakeFiles/bpg.dir/src/MainVerification.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bpg.dir/src/MainVerification.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/MainVerification.cpp" > CMakeFiles/bpg.dir/src/MainVerification.cpp.i

CMakeFiles/bpg.dir/src/MainVerification.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bpg.dir/src/MainVerification.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/MainVerification.cpp" -o CMakeFiles/bpg.dir/src/MainVerification.cpp.s

CMakeFiles/bpg.dir/src/MainVerification.cpp.o.requires:

.PHONY : CMakeFiles/bpg.dir/src/MainVerification.cpp.o.requires

CMakeFiles/bpg.dir/src/MainVerification.cpp.o.provides: CMakeFiles/bpg.dir/src/MainVerification.cpp.o.requires
	$(MAKE) -f CMakeFiles/bpg.dir/build.make CMakeFiles/bpg.dir/src/MainVerification.cpp.o.provides.build
.PHONY : CMakeFiles/bpg.dir/src/MainVerification.cpp.o.provides

CMakeFiles/bpg.dir/src/MainVerification.cpp.o.provides.build: CMakeFiles/bpg.dir/src/MainVerification.cpp.o


CMakeFiles/bpg.dir/src/Ship.cpp.o: CMakeFiles/bpg.dir/flags.make
CMakeFiles/bpg.dir/src/Ship.cpp.o: ../src/Ship.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bpg.dir/src/Ship.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bpg.dir/src/Ship.cpp.o -c "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/Ship.cpp"

CMakeFiles/bpg.dir/src/Ship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bpg.dir/src/Ship.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/Ship.cpp" > CMakeFiles/bpg.dir/src/Ship.cpp.i

CMakeFiles/bpg.dir/src/Ship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bpg.dir/src/Ship.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/Ship.cpp" -o CMakeFiles/bpg.dir/src/Ship.cpp.s

CMakeFiles/bpg.dir/src/Ship.cpp.o.requires:

.PHONY : CMakeFiles/bpg.dir/src/Ship.cpp.o.requires

CMakeFiles/bpg.dir/src/Ship.cpp.o.provides: CMakeFiles/bpg.dir/src/Ship.cpp.o.requires
	$(MAKE) -f CMakeFiles/bpg.dir/build.make CMakeFiles/bpg.dir/src/Ship.cpp.o.provides.build
.PHONY : CMakeFiles/bpg.dir/src/Ship.cpp.o.provides

CMakeFiles/bpg.dir/src/Ship.cpp.o.provides.build: CMakeFiles/bpg.dir/src/Ship.cpp.o


CMakeFiles/bpg.dir/src/battleship.cpp.o: CMakeFiles/bpg.dir/flags.make
CMakeFiles/bpg.dir/src/battleship.cpp.o: ../src/battleship.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bpg.dir/src/battleship.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bpg.dir/src/battleship.cpp.o -c "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/battleship.cpp"

CMakeFiles/bpg.dir/src/battleship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bpg.dir/src/battleship.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/battleship.cpp" > CMakeFiles/bpg.dir/src/battleship.cpp.i

CMakeFiles/bpg.dir/src/battleship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bpg.dir/src/battleship.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/battleship.cpp" -o CMakeFiles/bpg.dir/src/battleship.cpp.s

CMakeFiles/bpg.dir/src/battleship.cpp.o.requires:

.PHONY : CMakeFiles/bpg.dir/src/battleship.cpp.o.requires

CMakeFiles/bpg.dir/src/battleship.cpp.o.provides: CMakeFiles/bpg.dir/src/battleship.cpp.o.requires
	$(MAKE) -f CMakeFiles/bpg.dir/build.make CMakeFiles/bpg.dir/src/battleship.cpp.o.provides.build
.PHONY : CMakeFiles/bpg.dir/src/battleship.cpp.o.provides

CMakeFiles/bpg.dir/src/battleship.cpp.o.provides.build: CMakeFiles/bpg.dir/src/battleship.cpp.o


CMakeFiles/bpg.dir/src/main.cpp.o: CMakeFiles/bpg.dir/flags.make
CMakeFiles/bpg.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/bpg.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bpg.dir/src/main.cpp.o -c "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/main.cpp"

CMakeFiles/bpg.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bpg.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/main.cpp" > CMakeFiles/bpg.dir/src/main.cpp.i

CMakeFiles/bpg.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bpg.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/src/main.cpp" -o CMakeFiles/bpg.dir/src/main.cpp.s

CMakeFiles/bpg.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/bpg.dir/src/main.cpp.o.requires

CMakeFiles/bpg.dir/src/main.cpp.o.provides: CMakeFiles/bpg.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/bpg.dir/build.make CMakeFiles/bpg.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/bpg.dir/src/main.cpp.o.provides

CMakeFiles/bpg.dir/src/main.cpp.o.provides.build: CMakeFiles/bpg.dir/src/main.cpp.o


# Object files for target bpg
bpg_OBJECTS = \
"CMakeFiles/bpg.dir/src/MainVerification.cpp.o" \
"CMakeFiles/bpg.dir/src/Ship.cpp.o" \
"CMakeFiles/bpg.dir/src/battleship.cpp.o" \
"CMakeFiles/bpg.dir/src/main.cpp.o"

# External object files for target bpg
bpg_EXTERNAL_OBJECTS =

bpg: CMakeFiles/bpg.dir/src/MainVerification.cpp.o
bpg: CMakeFiles/bpg.dir/src/Ship.cpp.o
bpg: CMakeFiles/bpg.dir/src/battleship.cpp.o
bpg: CMakeFiles/bpg.dir/src/main.cpp.o
bpg: CMakeFiles/bpg.dir/build.make
bpg: CMakeFiles/bpg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bpg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bpg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bpg.dir/build: bpg

.PHONY : CMakeFiles/bpg.dir/build

CMakeFiles/bpg.dir/requires: CMakeFiles/bpg.dir/src/MainVerification.cpp.o.requires
CMakeFiles/bpg.dir/requires: CMakeFiles/bpg.dir/src/Ship.cpp.o.requires
CMakeFiles/bpg.dir/requires: CMakeFiles/bpg.dir/src/battleship.cpp.o.requires
CMakeFiles/bpg.dir/requires: CMakeFiles/bpg.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/bpg.dir/requires

CMakeFiles/bpg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bpg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bpg.dir/clean

CMakeFiles/bpg.dir/depend:
	cd "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0" "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0" "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build" "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build" "/home/rafakroom/Documentos/ti/2semestre/itp/Battleship-Tabble-Generator 2.0/build/CMakeFiles/bpg.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bpg.dir/depend

