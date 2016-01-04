#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <Types.h>
#include <GL/gl.h>

namespace OpenGLWrapper {

    struct Vertex
    {
        GLfloat x, y, z;
        GLfloat nx, ny, nz;
        u_int32_t color;
    };

};

#endif
