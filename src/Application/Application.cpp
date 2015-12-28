#include <Application/Application.h>
#include <Window/Window.h>

using namespace OpenGLWrapper;

Application::Application()
    :_mainWindow(SharedWindow(new Window()))
{

}

Application::Application(SharedWindow window)
{
    _mainWindow = window;
}

Application::~Application()
{

}

int Application::run()
{
    if (_mainWindow) {
        _mainWindow->processEvents();
    }

    return 0;
}
