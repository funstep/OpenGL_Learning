cmake_minimum_required(VERSION 2.2)

include(DefaultConfig.cmake)

set(HEADERS_DIR ${PROJECT_DIR}/include)

set(LEARNING_OPEN_GL_INCLUDE_DIR ${LEARNING_OPEN_GL}/include)

SET(HEADER_FILES
    ${HEADERS_DIR}/Types.h
    ${HEADERS_DIR}/General.h
    ${HEADERS_DIR}/Window/Window.h
    ${HEADERS_DIR}/Application/Application.h
    ${HEADERS_DIR}/Render/Renderer.h
    ${HEADERS_DIR}/Render/Model.h
#    ${HEADERS_DIR}/Render/Vertex.h

    ${LEARNING_OPEN_GL_INCLUDE_DIR}/LearningOpenGLWindow.h
    ${LEARNING_OPEN_GL_INCLUDE_DIR}/LearningOpenGLRenderer.h
)
