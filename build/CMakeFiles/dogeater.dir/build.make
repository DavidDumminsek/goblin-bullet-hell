# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/david/tdp005_dogeater

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/tdp005_dogeater/build

# Include any dependencies generated for this target.
include CMakeFiles/dogeater.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dogeater.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dogeater.dir/flags.make

CMakeFiles/dogeater.dir/src/main.cc.o: CMakeFiles/dogeater.dir/flags.make
CMakeFiles/dogeater.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/tdp005_dogeater/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dogeater.dir/src/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dogeater.dir/src/main.cc.o -c /home/david/tdp005_dogeater/src/main.cc

CMakeFiles/dogeater.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dogeater.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/tdp005_dogeater/src/main.cc > CMakeFiles/dogeater.dir/src/main.cc.i

CMakeFiles/dogeater.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dogeater.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/tdp005_dogeater/src/main.cc -o CMakeFiles/dogeater.dir/src/main.cc.s

CMakeFiles/dogeater.dir/src/game.cc.o: CMakeFiles/dogeater.dir/flags.make
CMakeFiles/dogeater.dir/src/game.cc.o: ../src/game.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/tdp005_dogeater/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dogeater.dir/src/game.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dogeater.dir/src/game.cc.o -c /home/david/tdp005_dogeater/src/game.cc

CMakeFiles/dogeater.dir/src/game.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dogeater.dir/src/game.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/tdp005_dogeater/src/game.cc > CMakeFiles/dogeater.dir/src/game.cc.i

CMakeFiles/dogeater.dir/src/game.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dogeater.dir/src/game.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/tdp005_dogeater/src/game.cc -o CMakeFiles/dogeater.dir/src/game.cc.s

CMakeFiles/dogeater.dir/src/entity.cc.o: CMakeFiles/dogeater.dir/flags.make
CMakeFiles/dogeater.dir/src/entity.cc.o: ../src/entity.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/tdp005_dogeater/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/dogeater.dir/src/entity.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dogeater.dir/src/entity.cc.o -c /home/david/tdp005_dogeater/src/entity.cc

CMakeFiles/dogeater.dir/src/entity.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dogeater.dir/src/entity.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/tdp005_dogeater/src/entity.cc > CMakeFiles/dogeater.dir/src/entity.cc.i

CMakeFiles/dogeater.dir/src/entity.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dogeater.dir/src/entity.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/tdp005_dogeater/src/entity.cc -o CMakeFiles/dogeater.dir/src/entity.cc.s

CMakeFiles/dogeater.dir/src/enemy.cc.o: CMakeFiles/dogeater.dir/flags.make
CMakeFiles/dogeater.dir/src/enemy.cc.o: ../src/enemy.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/tdp005_dogeater/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/dogeater.dir/src/enemy.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dogeater.dir/src/enemy.cc.o -c /home/david/tdp005_dogeater/src/enemy.cc

CMakeFiles/dogeater.dir/src/enemy.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dogeater.dir/src/enemy.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/tdp005_dogeater/src/enemy.cc > CMakeFiles/dogeater.dir/src/enemy.cc.i

CMakeFiles/dogeater.dir/src/enemy.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dogeater.dir/src/enemy.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/tdp005_dogeater/src/enemy.cc -o CMakeFiles/dogeater.dir/src/enemy.cc.s

CMakeFiles/dogeater.dir/src/player.cc.o: CMakeFiles/dogeater.dir/flags.make
CMakeFiles/dogeater.dir/src/player.cc.o: ../src/player.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/tdp005_dogeater/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/dogeater.dir/src/player.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dogeater.dir/src/player.cc.o -c /home/david/tdp005_dogeater/src/player.cc

CMakeFiles/dogeater.dir/src/player.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dogeater.dir/src/player.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/tdp005_dogeater/src/player.cc > CMakeFiles/dogeater.dir/src/player.cc.i

CMakeFiles/dogeater.dir/src/player.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dogeater.dir/src/player.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/tdp005_dogeater/src/player.cc -o CMakeFiles/dogeater.dir/src/player.cc.s

CMakeFiles/dogeater.dir/src/projectile.cc.o: CMakeFiles/dogeater.dir/flags.make
CMakeFiles/dogeater.dir/src/projectile.cc.o: ../src/projectile.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/tdp005_dogeater/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/dogeater.dir/src/projectile.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dogeater.dir/src/projectile.cc.o -c /home/david/tdp005_dogeater/src/projectile.cc

CMakeFiles/dogeater.dir/src/projectile.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dogeater.dir/src/projectile.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/tdp005_dogeater/src/projectile.cc > CMakeFiles/dogeater.dir/src/projectile.cc.i

CMakeFiles/dogeater.dir/src/projectile.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dogeater.dir/src/projectile.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/tdp005_dogeater/src/projectile.cc -o CMakeFiles/dogeater.dir/src/projectile.cc.s

# Object files for target dogeater
dogeater_OBJECTS = \
"CMakeFiles/dogeater.dir/src/main.cc.o" \
"CMakeFiles/dogeater.dir/src/game.cc.o" \
"CMakeFiles/dogeater.dir/src/entity.cc.o" \
"CMakeFiles/dogeater.dir/src/enemy.cc.o" \
"CMakeFiles/dogeater.dir/src/player.cc.o" \
"CMakeFiles/dogeater.dir/src/projectile.cc.o"

# External object files for target dogeater
dogeater_EXTERNAL_OBJECTS =

dogeater: CMakeFiles/dogeater.dir/src/main.cc.o
dogeater: CMakeFiles/dogeater.dir/src/game.cc.o
dogeater: CMakeFiles/dogeater.dir/src/entity.cc.o
dogeater: CMakeFiles/dogeater.dir/src/enemy.cc.o
dogeater: CMakeFiles/dogeater.dir/src/player.cc.o
dogeater: CMakeFiles/dogeater.dir/src/projectile.cc.o
dogeater: CMakeFiles/dogeater.dir/build.make
dogeater: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
dogeater: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
dogeater: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
dogeater: CMakeFiles/dogeater.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/tdp005_dogeater/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable dogeater"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dogeater.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dogeater.dir/build: dogeater

.PHONY : CMakeFiles/dogeater.dir/build

CMakeFiles/dogeater.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dogeater.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dogeater.dir/clean

CMakeFiles/dogeater.dir/depend:
	cd /home/david/tdp005_dogeater/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/tdp005_dogeater /home/david/tdp005_dogeater /home/david/tdp005_dogeater/build /home/david/tdp005_dogeater/build /home/david/tdp005_dogeater/build/CMakeFiles/dogeater.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dogeater.dir/depend
