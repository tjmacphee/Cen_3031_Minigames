//
// Created by Tyler MacPhee on 10/23/22.
//

#ifndef CEN_3031_MINIGAMES_MENU_H
#define CEN_3031_MINIGAMES_MENU_H

#pragma once
#include "SFML/Graphics.hpp"

#define MAX_MENU_ITEMS 5

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_MENU_ITEMS];

};
#endif //CEN_3031_MINIGAMES_MENU_H