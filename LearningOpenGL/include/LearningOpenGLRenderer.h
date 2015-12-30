#ifndef __LEANING_OPEN_GL_RENDERER_H__
#define __LEANING_OPEN_GL_RENDERER_H__

#include <Types.h>
#include <Render/Renderer.h>

namespace LearningOpenGL {

    class LearningOpenGLRenderer: public OpenGLWrapper::Renderer
    {
        public:
            LearningOpenGLRenderer();
            ~LearningOpenGLRenderer();

            virtual void render() const;
    };

};

#endif
