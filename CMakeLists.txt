cmake_minimum_required(VERSION 3.10)
project("Binary Tree" C)


set(CMAKE_C_FLAGS "-Wall -Wextra -std=c99 -pipe -fno-plt  ")
set(CMAKE_C_FLAGS_DEBUG "-g -O -fdiagnostics-color=always -fdiagnostics-show-option -fno-omit-frame-pointer -fno-inline")
set(CMAKE_C_FLAGS_RELEASE "-O2 -march=nativei -mtune=native -flto -fno-semantic-interposition -fno-plt -fno-stack-protector -fno-stack-clash-protection -fno-jump-tables -fno-plt")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

if(BUILD_PLATFORM STREQUAL "x86_64")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
endif()


if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG}")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE}")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 17)

add_library(treenode src/node.c)
target_include_directories(treenode PUBLIC include)

add_executable(test_node test/test_node.c)
target_include_directories(test_node PUBLIC include)
target_link_libraries(test_node treenode)

add_library(binary_node src/binary_node.c)
target_include_directories(binary_node PUBLIC include)
target_link_libraries(binary_node treenode)

add_executable(test_binary_node test/test_binary_node.c)
target_include_directories(test_binary_node PUBLIC include)
target_link_libraries(test_binary_node binary_node)


add_library(tree src/tree.c)
target_include_directories(tree PUBLIC include)
target_link_libraries(tree treenode)

## node tree gui

add_subdirectory(lib/raylib)

add_executable(test_binary_gui test/test_binary_gui.c)
target_include_directories(test_binary_gui PUBLIC include)
target_link_libraries(test_binary_gui binary_node raylib)
