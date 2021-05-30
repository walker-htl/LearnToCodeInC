cmake_minimum_required(VERSION 3.19)
project(12_Header_Dateien C)

set(CMAKE_C_STANDARD 99)

add_executable(12_Header_Dateien main.c myMath.c myMath.h testMyMath.c testMyMath.h)

target_link_libraries(12_Header_Dateien m)