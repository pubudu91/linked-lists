cmake_minimum_required(VERSION 3.5)
project(linked_lists)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES node.h main.c linked-list.c)
add_executable(linked_lists ${SOURCE_FILES} node-list-mutex.c)