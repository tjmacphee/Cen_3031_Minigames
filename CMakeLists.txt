cmake_minimum_required(VERSION 3.21)
project(Cen_3031_Minigames)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_OSX_ARCHITECTURES arm64)
set(CMAKE_CXX_STANDARD 17)

add_executable(Cen_3031_Minigames main.cpp Menu.cpp Hangman.cpp breakout1.cpp)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIRS})
    target_link_libraries(Cen_3031_Minigames sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
else()
    message(FATAL_ERROR "SFML not found!")
endif()