#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL Learning");
 
    sf::Event event;
    while(window.isOpen()) {

        while(window.pollEvent(event)) { 

            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }
    }

    return 0;
}
