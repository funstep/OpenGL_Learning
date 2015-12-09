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

Window::~Window()
{
    close();

    delete _window;
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

void Window::close()
{
    if (_window) {
        _window->close();
    }
}

sf::RenderWindow* Window::externalWindow()
{
    if (!_window) {
        _window = new sf::RenderWindow(sf::VideoMode(_width, _height), _windowTitle);
    }

    return _window;
}

void Window::translateEvent(sf::Event &event)
{
    if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
        onClose();
    }
}

void Window::draw()
{

}

void Window::onClose()
{
    externalWindow()->close();
}

bool Window::processEvents()
{
    sf::Event event;
    while(externalWindow()->isOpen()) {

        while(externalWindow()->pollEvent(event)) {
             translateEvent(event);
        }

        externalWindow()->clear();

        draw();

        externalWindow()->display();
    }
}
