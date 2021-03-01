cmake_minimum_required(VERSION 3.17)
project(03_Arrays C)

set(CMAKE_C_STANDARD 99)

add_executable(03_Arrays  main.c)

target_link_libraries(03_Arrays  m)