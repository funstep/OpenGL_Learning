#include <SFML/Graphics.hpp>
#include <Types.h>
#include <Render/Renderer.h>

namespace OpenGLWrapper {

    class Renderer;
    typedef std::shared_ptr<Renderer> SharedRenderer;

    class Window {
            friend class Application;

        protected:
            sf::RenderWindow *_window;
            std::string _windowTitle;

        public:
            PROPERTY(int, width, setWidth)
            PROPERTY(int, height, setHeight)
            READ_ONLY_PROPERTY(bool, isFullscreen)
            PROPERTY(SharedRenderer, renderer, setRenderer)

        public:
            Window();
            Window(int width, int height);
            virtual ~Window();

            void setTitle(std::string &title);

            virtual void show();
            virtual void hide();
            virtual void close();

        private:
            sf::RenderWindow *externalWindow();

            bool processEvents();

        protected:
            virtual void draw();
            virtual void translateEvent(sf::Event &event);
            virtual void translateKeyPress(sf::Event &event, sf::Keyboard::Key key);
            virtual void toogleFullsreen();

            virtual void onClose();
    };

};
