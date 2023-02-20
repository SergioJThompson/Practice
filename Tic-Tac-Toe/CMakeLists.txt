cmake_minimum_required(VERSION 3.7)

project(Tic-Tac-Toe)

# Set the paths to the SDL2 and SDL2_image libraries
set(SDL2_INCLUDE_DIR /usr/local/include/SDL2)
set(SDL2_LIBRARY /usr/local/lib/libSDL2.dylib)
set(SDL2_IMAGE_INCLUDE_DIRS /usr/local/include/SDL2)
set(SDL2_IMAGE_LIBRARY /usr/local/lib/libSDL2_image.dylib)

# Find the SDL2 and SDL2_image libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Set the include directories for the project
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Create the executable and link against the SDL2 and SDL2_image libraries
add_executable(Tic-Tac-Toe main.cpp object.cpp)
target_link_libraries(Tic-Tac-Toe ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
