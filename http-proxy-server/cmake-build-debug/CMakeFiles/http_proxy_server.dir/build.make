# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/http_proxy_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/http_proxy_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/http_proxy_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/http_proxy_server.dir/flags.make

CMakeFiles/http_proxy_server.dir/proxy.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/proxy.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/proxy.c
CMakeFiles/http_proxy_server.dir/proxy.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/http_proxy_server.dir/proxy.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/proxy.c.o -MF CMakeFiles/http_proxy_server.dir/proxy.c.o.d -o CMakeFiles/http_proxy_server.dir/proxy.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/proxy.c"

CMakeFiles/http_proxy_server.dir/proxy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/proxy.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/proxy.c" > CMakeFiles/http_proxy_server.dir/proxy.c.i

CMakeFiles/http_proxy_server.dir/proxy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/proxy.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/proxy.c" -o CMakeFiles/http_proxy_server.dir/proxy.c.s

CMakeFiles/http_proxy_server.dir/websocket.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/websocket.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/websocket.c
CMakeFiles/http_proxy_server.dir/websocket.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/http_proxy_server.dir/websocket.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/websocket.c.o -MF CMakeFiles/http_proxy_server.dir/websocket.c.o.d -o CMakeFiles/http_proxy_server.dir/websocket.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/websocket.c"

CMakeFiles/http_proxy_server.dir/websocket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/websocket.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/websocket.c" > CMakeFiles/http_proxy_server.dir/websocket.c.i

CMakeFiles/http_proxy_server.dir/websocket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/websocket.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/websocket.c" -o CMakeFiles/http_proxy_server.dir/websocket.c.s

CMakeFiles/http_proxy_server.dir/error_utils.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/error_utils.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/error_utils.c
CMakeFiles/http_proxy_server.dir/error_utils.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/http_proxy_server.dir/error_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/error_utils.c.o -MF CMakeFiles/http_proxy_server.dir/error_utils.c.o.d -o CMakeFiles/http_proxy_server.dir/error_utils.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/error_utils.c"

CMakeFiles/http_proxy_server.dir/error_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/error_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/error_utils.c" > CMakeFiles/http_proxy_server.dir/error_utils.c.i

CMakeFiles/http_proxy_server.dir/error_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/error_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/error_utils.c" -o CMakeFiles/http_proxy_server.dir/error_utils.c.s

CMakeFiles/http_proxy_server.dir/req_handler.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/req_handler.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/req_handler.c
CMakeFiles/http_proxy_server.dir/req_handler.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/http_proxy_server.dir/req_handler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/req_handler.c.o -MF CMakeFiles/http_proxy_server.dir/req_handler.c.o.d -o CMakeFiles/http_proxy_server.dir/req_handler.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/req_handler.c"

CMakeFiles/http_proxy_server.dir/req_handler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/req_handler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/req_handler.c" > CMakeFiles/http_proxy_server.dir/req_handler.c.i

CMakeFiles/http_proxy_server.dir/req_handler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/req_handler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/req_handler.c" -o CMakeFiles/http_proxy_server.dir/req_handler.c.s

CMakeFiles/http_proxy_server.dir/utils.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/utils.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/utils.c
CMakeFiles/http_proxy_server.dir/utils.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/http_proxy_server.dir/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/utils.c.o -MF CMakeFiles/http_proxy_server.dir/utils.c.o.d -o CMakeFiles/http_proxy_server.dir/utils.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/utils.c"

CMakeFiles/http_proxy_server.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/utils.c" > CMakeFiles/http_proxy_server.dir/utils.c.i

CMakeFiles/http_proxy_server.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/utils.c" -o CMakeFiles/http_proxy_server.dir/utils.c.s

CMakeFiles/http_proxy_server.dir/res_handler.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/res_handler.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/res_handler.c
CMakeFiles/http_proxy_server.dir/res_handler.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/http_proxy_server.dir/res_handler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/res_handler.c.o -MF CMakeFiles/http_proxy_server.dir/res_handler.c.o.d -o CMakeFiles/http_proxy_server.dir/res_handler.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/res_handler.c"

CMakeFiles/http_proxy_server.dir/res_handler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/res_handler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/res_handler.c" > CMakeFiles/http_proxy_server.dir/res_handler.c.i

CMakeFiles/http_proxy_server.dir/res_handler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/res_handler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/res_handler.c" -o CMakeFiles/http_proxy_server.dir/res_handler.c.s

CMakeFiles/http_proxy_server.dir/file_ops.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/file_ops.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/file_ops.c
CMakeFiles/http_proxy_server.dir/file_ops.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/http_proxy_server.dir/file_ops.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/file_ops.c.o -MF CMakeFiles/http_proxy_server.dir/file_ops.c.o.d -o CMakeFiles/http_proxy_server.dir/file_ops.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/file_ops.c"

CMakeFiles/http_proxy_server.dir/file_ops.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/file_ops.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/file_ops.c" > CMakeFiles/http_proxy_server.dir/file_ops.c.i

CMakeFiles/http_proxy_server.dir/file_ops.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/file_ops.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/file_ops.c" -o CMakeFiles/http_proxy_server.dir/file_ops.c.s

CMakeFiles/http_proxy_server.dir/dns_cache.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/dns_cache.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/dns_cache.c
CMakeFiles/http_proxy_server.dir/dns_cache.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/http_proxy_server.dir/dns_cache.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/dns_cache.c.o -MF CMakeFiles/http_proxy_server.dir/dns_cache.c.o.d -o CMakeFiles/http_proxy_server.dir/dns_cache.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/dns_cache.c"

CMakeFiles/http_proxy_server.dir/dns_cache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/dns_cache.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/dns_cache.c" > CMakeFiles/http_proxy_server.dir/dns_cache.c.i

CMakeFiles/http_proxy_server.dir/dns_cache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/dns_cache.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/dns_cache.c" -o CMakeFiles/http_proxy_server.dir/dns_cache.c.s

CMakeFiles/http_proxy_server.dir/blacklist.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/blacklist.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/blacklist.c
CMakeFiles/http_proxy_server.dir/blacklist.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/http_proxy_server.dir/blacklist.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/blacklist.c.o -MF CMakeFiles/http_proxy_server.dir/blacklist.c.o.d -o CMakeFiles/http_proxy_server.dir/blacklist.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/blacklist.c"

CMakeFiles/http_proxy_server.dir/blacklist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/blacklist.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/blacklist.c" > CMakeFiles/http_proxy_server.dir/blacklist.c.i

CMakeFiles/http_proxy_server.dir/blacklist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/blacklist.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/blacklist.c" -o CMakeFiles/http_proxy_server.dir/blacklist.c.s

CMakeFiles/http_proxy_server.dir/page_cache.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/page_cache.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/page_cache.c
CMakeFiles/http_proxy_server.dir/page_cache.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/http_proxy_server.dir/page_cache.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/page_cache.c.o -MF CMakeFiles/http_proxy_server.dir/page_cache.c.o.d -o CMakeFiles/http_proxy_server.dir/page_cache.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/page_cache.c"

CMakeFiles/http_proxy_server.dir/page_cache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/page_cache.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/page_cache.c" > CMakeFiles/http_proxy_server.dir/page_cache.c.i

CMakeFiles/http_proxy_server.dir/page_cache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/page_cache.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/page_cache.c" -o CMakeFiles/http_proxy_server.dir/page_cache.c.s

CMakeFiles/http_proxy_server.dir/dir_ops.c.o: CMakeFiles/http_proxy_server.dir/flags.make
CMakeFiles/http_proxy_server.dir/dir_ops.c.o: /mnt/d/Cu\ Boulder/Fall\ 23/Network\ Systems/Programming\ Assignments/Assignment\ 3/http_proxy_server/dir_ops.c
CMakeFiles/http_proxy_server.dir/dir_ops.c.o: CMakeFiles/http_proxy_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/http_proxy_server.dir/dir_ops.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/http_proxy_server.dir/dir_ops.c.o -MF CMakeFiles/http_proxy_server.dir/dir_ops.c.o.d -o CMakeFiles/http_proxy_server.dir/dir_ops.c.o -c "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/dir_ops.c"

CMakeFiles/http_proxy_server.dir/dir_ops.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/http_proxy_server.dir/dir_ops.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/dir_ops.c" > CMakeFiles/http_proxy_server.dir/dir_ops.c.i

CMakeFiles/http_proxy_server.dir/dir_ops.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/http_proxy_server.dir/dir_ops.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/dir_ops.c" -o CMakeFiles/http_proxy_server.dir/dir_ops.c.s

# Object files for target http_proxy_server
http_proxy_server_OBJECTS = \
"CMakeFiles/http_proxy_server.dir/proxy.c.o" \
"CMakeFiles/http_proxy_server.dir/websocket.c.o" \
"CMakeFiles/http_proxy_server.dir/error_utils.c.o" \
"CMakeFiles/http_proxy_server.dir/req_handler.c.o" \
"CMakeFiles/http_proxy_server.dir/utils.c.o" \
"CMakeFiles/http_proxy_server.dir/res_handler.c.o" \
"CMakeFiles/http_proxy_server.dir/file_ops.c.o" \
"CMakeFiles/http_proxy_server.dir/dns_cache.c.o" \
"CMakeFiles/http_proxy_server.dir/blacklist.c.o" \
"CMakeFiles/http_proxy_server.dir/page_cache.c.o" \
"CMakeFiles/http_proxy_server.dir/dir_ops.c.o"

# External object files for target http_proxy_server
http_proxy_server_EXTERNAL_OBJECTS =

http_proxy_server: CMakeFiles/http_proxy_server.dir/proxy.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/websocket.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/error_utils.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/req_handler.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/utils.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/res_handler.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/file_ops.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/dns_cache.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/blacklist.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/page_cache.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/dir_ops.c.o
http_proxy_server: CMakeFiles/http_proxy_server.dir/build.make
http_proxy_server: /usr/lib/x86_64-linux-gnu/libssl.so
http_proxy_server: /usr/lib/x86_64-linux-gnu/libcrypto.so
http_proxy_server: CMakeFiles/http_proxy_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable http_proxy_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/http_proxy_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/http_proxy_server.dir/build: http_proxy_server
.PHONY : CMakeFiles/http_proxy_server.dir/build

CMakeFiles/http_proxy_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/http_proxy_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/http_proxy_server.dir/clean

CMakeFiles/http_proxy_server.dir/depend:
	cd "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server" "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server" "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug" "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug" "/mnt/d/Cu Boulder/Fall 23/Network Systems/Programming Assignments/Assignment 3/http_proxy_server/cmake-build-debug/CMakeFiles/http_proxy_server.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/http_proxy_server.dir/depend

