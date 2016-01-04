cmake_minimum_required(VERSION 2.2)

include(DefaultConfig.cmake)
set(SOURCES_DIR ${PROJECT_DIR}/src)

set(LEARNING_OPEN_GL_SRC ${LEARNING_OPEN_GL}/src)

set(SOURCE_FILES
    ${SOURCES_DIR}/main.cpp
    ${SOURCES_DIR}/Window/Window.cpp
    ${SOURCES_DIR}/Application/Application.cpp
    ${SOURCES_DIR}/Render/Renderer.cpp
    ${SOURCES_DIR}/Render/Model.cpp
#    ${SOURCES_DIR}/Render/Vertex.cpp

    ${LEARNING_OPEN_GL_SRC}/LearningOpenGLWindow.cpp
    ${LEARNING_OPEN_GL_SRC}/LearningOpenGLRenderer.cpp
)
