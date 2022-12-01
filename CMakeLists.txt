cmake_minimum_required(VERSION 3.21)
project(Cen_3031_Minigames)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_OSX_ARCHITECTURES x86_64)

add_executable(Cen_3031_Minigames main.cpp Menu.cpp Hangman.cpp Hangman.h breakout1.cpp breakout_defs.h)
set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "/usr/local/include")
set(SFML_LIBRARY_DIR "/usr/local/lib")

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

target_link_libraries(Cen_3031_Minigames sfml-graphics sfml-window sfml-system)