#ifndef __REDERER_H__
#define __REDERER_H__

#include <vector>
#include <Types.h>

namespace OpenGLWrapper {

    class Renderer
    {
        public:
            Renderer();
            virtual ~Renderer();

            virtual void render() const = 0;
    };

};

#endif
