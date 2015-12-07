cmake_minimum_required(VERSION 2.2)

include(DefaultConfig.cmake)

set(HEADERS_DIR ${PROJECT_DIR}/include)

SET(HEADER_FILES
    ${HEADERS_DIR}/Types.h
    ${HEADERS_DIR}/General.h
    ${HEADERS_DIR}/Window/Window.h
)
