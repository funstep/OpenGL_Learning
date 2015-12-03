cmake_minimum_required(VERSION 2.2)

include(./DefaultConfig.cmake)
include(./src/CMakeLists.txt)

message(${SOURCE_FILES})
add_executable(${TARGET_NAME} ${SOURCE_FILES})
target_link_libraries(${TARGET_NAME} -lsfml-graphics -lsfml-window -lsfml-system)
