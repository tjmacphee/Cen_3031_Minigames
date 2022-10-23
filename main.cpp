#include <iostream>
#include "SFML/include/SFML/Graphics.hpp"
#include "menu.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORKING");

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();

        menu.draw(window);

        window.display();
    }
    //change

    return 0;
}
