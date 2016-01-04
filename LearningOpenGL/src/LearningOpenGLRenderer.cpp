#include <SFML/Graphics/RenderWindow.hpp>
#include <LearningOpenGLRenderer.h>

using namespace LearningOpenGL;
using namespace OpenGLWrapper;

LearningOpenGLRenderer::LearningOpenGLRenderer()
{

}

LearningOpenGLRenderer::~LearningOpenGLRenderer()
{

}

void LearningOpenGLRenderer::render(SharedSFMLWindow window)
{
    window->clear(sf::Color(255, 255, 255, 255));
}
