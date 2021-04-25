cmake_minimum_required(VERSION 3.17)
project(02_Basics C)

set(CMAKE_C_STANDARD 99)

add_executable(02_Basics main.c)

target_link_libraries(02_Basics m)