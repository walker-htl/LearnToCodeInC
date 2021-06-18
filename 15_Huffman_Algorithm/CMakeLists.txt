cmake_minimum_required(VERSION 3.19)
project(15_Huffman_Algorithm C)

set(CMAKE_C_STANDARD 99)

add_executable(15_Huffman_Algorithm main.c huffman_tree.h huffman_tree.c sorted_list.c sorted_list.h)