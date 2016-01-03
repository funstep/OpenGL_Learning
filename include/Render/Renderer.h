#ifndef __REDERER_H__
#define __REDERER_H__

#include <vector>
#include <Types.h>

namespace sf {
    class Window;
};

namespace OpenGLWrapper {

    typedef std::shared_ptr<sf::Window> SharedSFMLWindow;

    class Renderer
    {
        public:
            Renderer();
            virtual ~Renderer();

            virtual void render(SharedSFMLWindow) = 0;
    };

};

#endif
