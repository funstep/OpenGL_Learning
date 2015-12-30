#include <Types.h>

namespace OpenGLWrapper {

class Window;
typedef std::shared_ptr<Window> SharedWindow;

    class Application {
        public:
            READ_ONLY_PROPERTY(SharedWindow, mainWindow)

        public:
            Application();
            Application(SharedWindow window);

            virtual ~Application();

            virtual int run();
    };

};
