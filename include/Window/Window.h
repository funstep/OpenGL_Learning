#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SFML/Graphics.hpp>
#include <Types.h>
#include <Render/Renderer.h>

namespace OpenGLWrapper {

    class Renderer;
    typedef std::shared_ptr<Renderer> SharedRenderer;

    class Window {
            friend class Application;

        protected:
            std::shared_ptr<sf::RenderWindow> _window;
            std::string _windowTitle;
            sf::ContextSettings _contextSettings;

        public:
            PROPERTY(int, width, setWidth)
            PROPERTY(int, height, setHeight)
            READ_ONLY_PROPERTY(bool, isFullscreen)
            READ_ONLY_PROPERTY(SharedRenderer, renderer)

        public:
            Window();
            Window(int width, int height);
            virtual ~Window();

            void setTitle(std::string &title);

            virtual void show();
            virtual void hide();
            virtual void close();

        private:
            std::shared_ptr<sf::RenderWindow> externalWindow();

            bool processEvents();

        protected:
            virtual void draw();
            virtual void translateEvent(sf::Event &event);
            virtual void translateKeyPress(sf::Event &event, sf::Keyboard::Key key);
            virtual void toogleFullsreen();

            virtual void onClose();
    };

};

#endif
