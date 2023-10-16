cmake_minimum_required(VERSION 3.24)
project(CS_300_Binary_Search_Tree_Assignment_Student_Files)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS_300_Binary_Search_Tree_Assignment_Student_Files
        BinarySearchTree.cpp
        CSVparser.cpp
        CSVparser.hpp)
