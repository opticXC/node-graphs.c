cmake_minimum_required(VERSION 3.10)
project("Binary Tree" C)


set(CMAKE_C_FLAGS "-Wall -Wextra -std=c99")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3 -march=native")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

if(BUILD_PLATFORM STREQUAL "x86_64")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
endif()


if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
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

