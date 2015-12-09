#include <Types.h>

namespace LearningOpenGL {

class Window;
typedef std::shared_ptr<Window> SharedWindow;

    class Application {
        SharedWindow _mainWindow;

        public:
            Application();
            Application(SharedWindow window);

            virtual ~Application();

            virtual int run();
    };

};
