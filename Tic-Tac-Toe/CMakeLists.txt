cmake_minimum_required(VERSION 3.7)

project(Tic-Tac-Toe)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Tic-Tac-Toe main.cpp)
target_link_libraries(Tic-Tac-Toe ${SDL2_LIBRARIES})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(Tic-Tac-Toe ${SDL2_IMAGE_LIBRARY})
