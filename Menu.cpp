//
// Created by Tyler MacPhee on 10/23/22.
//
#include "menu.h"

using namespace std;

Menu::Menu(float width, float height) {
    if(!font.loadFromFile("Calibri Regular.ttf"))
    {
        //error
    }
    //first menu item
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width /2,  height / (MAX_MENU_ITEMS + 1) * 1 ));

    //second menu item
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width /2,  height / (MAX_MENU_ITEMS + 1) * 2 ));

    //third menu item
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width /2,  height / (MAX_MENU_ITEMS + 1) * 3 ));
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
    for (int i=0; i<MAX_MENU_ITEMS; i++) {
        window.draw(menu[i]);
    }
}
