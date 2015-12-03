cmake_minimum_required(VERSION 2.2)
project(OpenGL_Learning)

include(./DefaultConfig.cmake)
add_subdirectory(./src)
 
set(SOURCE_FILES ./src/main.cpp)

add_executable(OpenGL_Learning ${SOURCE_FILES})
target_link_libraries(OpenGL_Learning -lsfml-graphics -lsfml-window -lsfml-system)
