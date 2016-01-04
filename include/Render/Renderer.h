#ifndef __REDERER_H__
#define __REDERER_H__

#include <Types.h>

namespace sf {
    class RenderWindow;
};

namespace OpenGLWrapper {

    typedef std::shared_ptr<sf::RenderWindow> SharedSFMLWindow;

    class Renderer
    {
        public:
            Renderer();
            virtual ~Renderer();

            virtual void render(SharedSFMLWindow) = 0;
    };

};

#endif
