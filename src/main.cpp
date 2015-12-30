#include <Application/Application.h>
#include <LearningOpenGLWindow.h>

using namespace OpenGLWrapper;
using namespace LearningOpenGL;

int main()
{
    Application app(SharedWindow(new LearningOpenGLWindow()));
    return app.run();
}
