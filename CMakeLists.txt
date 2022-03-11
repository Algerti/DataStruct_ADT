cmake_minimum_required(VERSION 3.19)
project(DataStruct_ADT C)

set(CMAKE_C_STANDARD 11)

include_directories("binary search tree")

add_executable(BST
        "binary search tree/bst.c"
        "binary search tree/bst.h"
        "binary search tree/here_main.c")
