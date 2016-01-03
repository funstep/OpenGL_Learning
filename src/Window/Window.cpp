#include <Window/Window.h>

using namespace OpenGLWrapper;
using namespace std;

Window::Window()
    :Window(800, 600)
{

}

Window::Window(int width, int height)
    :_window(NULL),
      _windowTitle("Window"),
      _isFullscreen(false)
{
    _width = width;
    _height = height;
}

Window::~Window()
{
    close();
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

std::shared_ptr<sf::RenderWindow> Window::externalWindow()
{
    if (!_window) {
        _window = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(
                    sf::VideoMode(_width, _height),
                    _windowTitle,
                    _isFullscreen ? sf::Style::Fullscreen : sf::Style::Default, _contextSettings));
    }

    return _window;
}

void Window::translateEvent(sf::Event &event)
{
    switch(event.type) {
        case sf::Event::Closed:
            onClose();
            break;
        case sf::Event::KeyPressed:
            translateKeyPress(event, event.key.code);
            break;
        default:
            break;
    }
}

void Window::translateKeyPress(sf::Event &event, sf::Keyboard::Key key)
{
    switch(key) {
        case sf::Keyboard::Escape:
            onClose();
            break;
// TODO: think about implementation
//        case sf::Keyboard::F:
//            toogleFullsreen();
//            break;
        default:
            break;
    }
}

void Window::toogleFullsreen()
{
    _isFullscreen = !_isFullscreen;

    if (_window->isOpen()) {
        _window->close();
        _window.reset();
    }

    show();
}

void Window::draw()
{
    if (_renderer) {
        _renderer->render(_window);
    }
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
