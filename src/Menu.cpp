#include "Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("Fipps-Regular.tff"))
    {

    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEMS + 1)*1));


    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Red);
    menu[1].setString("Credits");
    menu[1].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEMS + 1)*2));


    menu[2].setFont(font);
    menu[2].setColor(sf::Color::Red);
    menu[2].setString("About");
    menu[2].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEMS + 1)*3));


    menu[3].setFont(font);
    menu[3].setColor(sf::Color::Red);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEMS + 1)*4));
}

Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window){
    for(int i=0; i<MAX_NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]);
    }
}