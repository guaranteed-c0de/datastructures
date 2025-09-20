cmake_minimum_required(VERSION 3.16)
project(MemoryGame VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(MemoryGame main.cpp)

find_package(Curses REQUIRED)
target_link_libraries(MemoryGame PRIVATE ${CURSES_LIBRARIES})
target_include_directories(MemoryGame PRIVATE ${CURSES_INCLUDE_DIR})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(MemoryGame PRIVATE sfml-graphics sfml-window sfml-system)
