#include <LearningOpenGLWindow.h>
#include <LearningOpenGLRenderer.h>

using namespace LearningOpenGL;
using namespace OpenGLWrapper;

LearningOpenGLWindow::LearningOpenGLWindow ()
    :Window()
{
     _renderer = SharedRenderer(new LearningOpenGLRenderer());
}

LearningOpenGLWindow::~LearningOpenGLWindow()
{

}


