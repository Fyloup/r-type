# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/philippe/Projects/CPP_rtype_2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/philippe/Projects/CPP_rtype_2019/build

# Include any dependencies generated for this target.
include src/server/CMakeFiles/r-type_server.dir/depend.make

# Include the progress variables for this target.
include src/server/CMakeFiles/r-type_server.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/CMakeFiles/r-type_server.dir/flags.make

src/server/CMakeFiles/r-type_server.dir/Main.cpp.o: src/server/CMakeFiles/r-type_server.dir/flags.make
src/server/CMakeFiles/r-type_server.dir/Main.cpp.o: ../src/server/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philippe/Projects/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/server/CMakeFiles/r-type_server.dir/Main.cpp.o"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r-type_server.dir/Main.cpp.o -c /home/philippe/Projects/CPP_rtype_2019/src/server/Main.cpp

src/server/CMakeFiles/r-type_server.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/Main.cpp.i"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philippe/Projects/CPP_rtype_2019/src/server/Main.cpp > CMakeFiles/r-type_server.dir/Main.cpp.i

src/server/CMakeFiles/r-type_server.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/Main.cpp.s"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philippe/Projects/CPP_rtype_2019/src/server/Main.cpp -o CMakeFiles/r-type_server.dir/Main.cpp.s

src/server/CMakeFiles/r-type_server.dir/game/Game.cpp.o: src/server/CMakeFiles/r-type_server.dir/flags.make
src/server/CMakeFiles/r-type_server.dir/game/Game.cpp.o: ../src/server/game/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philippe/Projects/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/server/CMakeFiles/r-type_server.dir/game/Game.cpp.o"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r-type_server.dir/game/Game.cpp.o -c /home/philippe/Projects/CPP_rtype_2019/src/server/game/Game.cpp

src/server/CMakeFiles/r-type_server.dir/game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/game/Game.cpp.i"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philippe/Projects/CPP_rtype_2019/src/server/game/Game.cpp > CMakeFiles/r-type_server.dir/game/Game.cpp.i

src/server/CMakeFiles/r-type_server.dir/game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/game/Game.cpp.s"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philippe/Projects/CPP_rtype_2019/src/server/game/Game.cpp -o CMakeFiles/r-type_server.dir/game/Game.cpp.s

src/server/CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.o: src/server/CMakeFiles/r-type_server.dir/flags.make
src/server/CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.o: ../src/server/gameEngine/engine/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philippe/Projects/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/server/CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.o"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.o -c /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/engine/Engine.cpp

src/server/CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.i"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/engine/Engine.cpp > CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.i

src/server/CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.s"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/engine/Engine.cpp -o CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.s

src/server/CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.o: src/server/CMakeFiles/r-type_server.dir/flags.make
src/server/CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.o: ../src/server/gameEngine/entity/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philippe/Projects/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/server/CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.o"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.o -c /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/entity/Entity.cpp

src/server/CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.i"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/entity/Entity.cpp > CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.i

src/server/CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.s"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/entity/Entity.cpp -o CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.s

src/server/CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.o: src/server/CMakeFiles/r-type_server.dir/flags.make
src/server/CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.o: ../src/server/gameEngine/network/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philippe/Projects/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/server/CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.o"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.o -c /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/network/Server.cpp

src/server/CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.i"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/network/Server.cpp > CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.i

src/server/CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.s"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philippe/Projects/CPP_rtype_2019/src/server/gameEngine/network/Server.cpp -o CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.s

src/server/CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.o: src/server/CMakeFiles/r-type_server.dir/flags.make
src/server/CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.o: ../src/shared/Protocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/philippe/Projects/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/server/CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.o"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.o -c /home/philippe/Projects/CPP_rtype_2019/src/shared/Protocol.cpp

src/server/CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.i"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/philippe/Projects/CPP_rtype_2019/src/shared/Protocol.cpp > CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.i

src/server/CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.s"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/philippe/Projects/CPP_rtype_2019/src/shared/Protocol.cpp -o CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.s

# Object files for target r-type_server
r__type_server_OBJECTS = \
"CMakeFiles/r-type_server.dir/Main.cpp.o" \
"CMakeFiles/r-type_server.dir/game/Game.cpp.o" \
"CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.o" \
"CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.o" \
"CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.o" \
"CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.o"

# External object files for target r-type_server
r__type_server_EXTERNAL_OBJECTS =

bin/r-type_server: src/server/CMakeFiles/r-type_server.dir/Main.cpp.o
bin/r-type_server: src/server/CMakeFiles/r-type_server.dir/game/Game.cpp.o
bin/r-type_server: src/server/CMakeFiles/r-type_server.dir/gameEngine/engine/Engine.cpp.o
bin/r-type_server: src/server/CMakeFiles/r-type_server.dir/gameEngine/entity/Entity.cpp.o
bin/r-type_server: src/server/CMakeFiles/r-type_server.dir/gameEngine/network/Server.cpp.o
bin/r-type_server: src/server/CMakeFiles/r-type_server.dir/__/shared/Protocol.cpp.o
bin/r-type_server: src/server/CMakeFiles/r-type_server.dir/build.make
bin/r-type_server: src/server/CMakeFiles/r-type_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/philippe/Projects/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../../bin/r-type_server"
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/r-type_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/CMakeFiles/r-type_server.dir/build: bin/r-type_server

.PHONY : src/server/CMakeFiles/r-type_server.dir/build

src/server/CMakeFiles/r-type_server.dir/clean:
	cd /home/philippe/Projects/CPP_rtype_2019/build/src/server && $(CMAKE_COMMAND) -P CMakeFiles/r-type_server.dir/cmake_clean.cmake
.PHONY : src/server/CMakeFiles/r-type_server.dir/clean

src/server/CMakeFiles/r-type_server.dir/depend:
	cd /home/philippe/Projects/CPP_rtype_2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/philippe/Projects/CPP_rtype_2019 /home/philippe/Projects/CPP_rtype_2019/src/server /home/philippe/Projects/CPP_rtype_2019/build /home/philippe/Projects/CPP_rtype_2019/build/src/server /home/philippe/Projects/CPP_rtype_2019/build/src/server/CMakeFiles/r-type_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/server/CMakeFiles/r-type_server.dir/depend

