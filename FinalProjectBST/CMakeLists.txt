cmake_minimum_required(VERSION 3.16)

project(FinalBST VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(FinalBST
    BSTMap_Driver.cpp
    Tree.cpp
)