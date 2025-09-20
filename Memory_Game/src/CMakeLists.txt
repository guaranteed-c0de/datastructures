cmake_minimum_required(VERSION 3.16)
project(MemoryGame VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_include_directories(GameLib PUBLIC include)

add_executable(MemoryGame src/main.cpp)
target_link_libraries(MemoryGame PRIVATE GameLib)

