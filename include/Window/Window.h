#include <SFML/Graphics.hpp>

#include <Types.h>

namespace LearningOpenGL {
    class Window {
        protected:
            sf::Window *_window;
            std::string _windowTitle;

        public:
            PROPERTY(int, width, setWidth)
            PROPERTY(int, height, setHeight)

        public:
            Window();
            Window(int width, int height);

            void setTitle(std::string &title);

            void show();
            void hide();

        private:
            sf::Window *externalWindow();
    };
};
