cmake_minimum_required(VERSION 2.2)

include(./DefaultConfig.cmake)
include(./src/Src.cmake)
include(./include/Include.cmake)

include_directories(./include)

add_executable(${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${TARGET_NAME} -lsfml-graphics -lsfml-window -lsfml-system)
