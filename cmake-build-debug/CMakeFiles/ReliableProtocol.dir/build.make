# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/benjaminmartinson/CLionProjects/ReliableProtocol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ReliableProtocol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ReliableProtocol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReliableProtocol.dir/flags.make

CMakeFiles/ReliableProtocol.dir/main.cpp.o: CMakeFiles/ReliableProtocol.dir/flags.make
CMakeFiles/ReliableProtocol.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReliableProtocol.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReliableProtocol.dir/main.cpp.o -c /Users/benjaminmartinson/CLionProjects/ReliableProtocol/main.cpp

CMakeFiles/ReliableProtocol.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReliableProtocol.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/benjaminmartinson/CLionProjects/ReliableProtocol/main.cpp > CMakeFiles/ReliableProtocol.dir/main.cpp.i

CMakeFiles/ReliableProtocol.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReliableProtocol.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/benjaminmartinson/CLionProjects/ReliableProtocol/main.cpp -o CMakeFiles/ReliableProtocol.dir/main.cpp.s

CMakeFiles/ReliableProtocol.dir/Packet.cpp.o: CMakeFiles/ReliableProtocol.dir/flags.make
CMakeFiles/ReliableProtocol.dir/Packet.cpp.o: ../Packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ReliableProtocol.dir/Packet.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReliableProtocol.dir/Packet.cpp.o -c /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Packet.cpp

CMakeFiles/ReliableProtocol.dir/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReliableProtocol.dir/Packet.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Packet.cpp > CMakeFiles/ReliableProtocol.dir/Packet.cpp.i

CMakeFiles/ReliableProtocol.dir/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReliableProtocol.dir/Packet.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Packet.cpp -o CMakeFiles/ReliableProtocol.dir/Packet.cpp.s

CMakeFiles/ReliableProtocol.dir/Client.cpp.o: CMakeFiles/ReliableProtocol.dir/flags.make
CMakeFiles/ReliableProtocol.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ReliableProtocol.dir/Client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReliableProtocol.dir/Client.cpp.o -c /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Client.cpp

CMakeFiles/ReliableProtocol.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReliableProtocol.dir/Client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Client.cpp > CMakeFiles/ReliableProtocol.dir/Client.cpp.i

CMakeFiles/ReliableProtocol.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReliableProtocol.dir/Client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Client.cpp -o CMakeFiles/ReliableProtocol.dir/Client.cpp.s

CMakeFiles/ReliableProtocol.dir/Server.cpp.o: CMakeFiles/ReliableProtocol.dir/flags.make
CMakeFiles/ReliableProtocol.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ReliableProtocol.dir/Server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReliableProtocol.dir/Server.cpp.o -c /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Server.cpp

CMakeFiles/ReliableProtocol.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReliableProtocol.dir/Server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Server.cpp > CMakeFiles/ReliableProtocol.dir/Server.cpp.i

CMakeFiles/ReliableProtocol.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReliableProtocol.dir/Server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/benjaminmartinson/CLionProjects/ReliableProtocol/Server.cpp -o CMakeFiles/ReliableProtocol.dir/Server.cpp.s

# Object files for target ReliableProtocol
ReliableProtocol_OBJECTS = \
"CMakeFiles/ReliableProtocol.dir/main.cpp.o" \
"CMakeFiles/ReliableProtocol.dir/Packet.cpp.o" \
"CMakeFiles/ReliableProtocol.dir/Client.cpp.o" \
"CMakeFiles/ReliableProtocol.dir/Server.cpp.o"

# External object files for target ReliableProtocol
ReliableProtocol_EXTERNAL_OBJECTS =

ReliableProtocol: CMakeFiles/ReliableProtocol.dir/main.cpp.o
ReliableProtocol: CMakeFiles/ReliableProtocol.dir/Packet.cpp.o
ReliableProtocol: CMakeFiles/ReliableProtocol.dir/Client.cpp.o
ReliableProtocol: CMakeFiles/ReliableProtocol.dir/Server.cpp.o
ReliableProtocol: CMakeFiles/ReliableProtocol.dir/build.make
ReliableProtocol: CMakeFiles/ReliableProtocol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ReliableProtocol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReliableProtocol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReliableProtocol.dir/build: ReliableProtocol

.PHONY : CMakeFiles/ReliableProtocol.dir/build

CMakeFiles/ReliableProtocol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReliableProtocol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReliableProtocol.dir/clean

CMakeFiles/ReliableProtocol.dir/depend:
	cd /Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/benjaminmartinson/CLionProjects/ReliableProtocol /Users/benjaminmartinson/CLionProjects/ReliableProtocol /Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug /Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug /Users/benjaminmartinson/CLionProjects/ReliableProtocol/cmake-build-debug/CMakeFiles/ReliableProtocol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReliableProtocol.dir/depend

