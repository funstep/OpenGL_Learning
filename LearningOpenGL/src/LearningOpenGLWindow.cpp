#include <LearningOpenGLWindow.h>
#include <LearningOpenGLRenderer.h>

using namespace LearningOpenGL;
using namespace OpenGLWrapper;

LearningOpenGLWindow::LearningOpenGLWindow ()
    :Window()
{
     _renderer = SharedRenderer(new LearningOpenGLRenderer());

     _contextSettings.depthBits = 24;
     _contextSettings.stencilBits = 8;
     _contextSettings.antialiasingLevel = 4;
     _contextSettings.majorVersion = 3;
     _contextSettings.minorVersion = 0;
}

LearningOpenGLWindow::~LearningOpenGLWindow()
{

}




