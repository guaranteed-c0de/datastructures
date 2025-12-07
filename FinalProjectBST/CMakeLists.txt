cmake_minimum_required(VERSION 3.16)

project(FinalBST VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(FinalBST FinakProjectBST/BSTMap_Driver.cpp FinalBST/Tree.cpp)

target_include_directories(FinalBST PUBLIC include)