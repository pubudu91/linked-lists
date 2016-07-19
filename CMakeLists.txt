cmake_minimum_required(VERSION 3.5)
project(linked_lists)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES node.h main.c linked-list.c ops.h operations.c linked-list-mutex.c linked-list-rwlock.c)
add_executable(linked_lists ${SOURCE_FILES})

target_link_libraries(linked_lists pthread)