cmake_minimum_required(VERSION 3.10)
project(MediaPlayer)

set(CMAKE_CXX_STANDARD)
#Enable testing
enable_testing()
#Fetch Catch2

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0 #Use the latest stable version version,
)

FetchContent_MakeAvailable(Catch2)

#Add test executable
add_executable(unit_tests test_playlist.cpp MediaPlayer.cpp)
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(unit_tests PUBLIC include)

#Discover and add tests to CTest
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)


#Find SFML installed via apt

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

#Tests target
add_executable(tests
tests_playlist.cpp
MediaPlayer.cpp
Song.cpp)

#Link SFML libraries (lowercase) and Catch2 if available
target_link_libraries(tests
    sfml-graphics
    sfml-audio
    sfml-window
    sfml-system
    Catch2::Catch2
    )

# Player target
add_executable(player
    MediaPlayler.cpp
    Song.cpp)

target_link_libraries(player
    sfml-graphics
    sfml-audio
    sfml-window
    sfml-system)
