#include <Window/Window.h>

using namespace LearningOpenGL;
using namespace std;

Window::Window()
    :Window(800, 600)
{

}

Window::Window(int width, int height)
    :_window(NULL),
      _windowTitle("Window")
{
    _width = width;
    _height = height;
}

void Window::setTitle(string &title)
{
    _windowTitle = title;

    if (_window) {
        _window->setTitle(_windowTitle);
    }
}

void Window::show()
{
    externalWindow()->setVisible(true);
}

void Window::hide()
{
    externalWindow()->setVisible(false);
}

sf::Window* Window::externalWindow()
{
    if (!_window) {
        _window = new sf::Window(sf::VideoMode(_width, _height), _windowTitle);
    }

    return _window;
}
