#include <SFML/Graphics.hpp>

#include <Types.h>

namespace LearningOpenGL {

    class Window {
            friend class Application;

        protected:
            sf::RenderWindow *_window;
            std::string _windowTitle;

        public:
            PROPERTY(int, width, setWidth)
            PROPERTY(int, height, setHeight)

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

            virtual void onClose();
    };

};
