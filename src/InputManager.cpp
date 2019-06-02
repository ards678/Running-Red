#include "InputManager.hpp"

namespace S{
    InputManager::InputManager(){

    }

    InputManager::~InputManager(){

    }

    bool InputManager::IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf:: RenderWindow &window){
        if(sf::Mouse::isButtonPressed(button)){
            sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
            if(playButtonRect.contains(sf::Mouse::getPosition(window))){
                return true;
            }
        }
        return false;
    }

    bool InputManager::Jump(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            return true;
        }
        return false;
    }

    bool InputManager::Slide(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            return true;
        }
        return false;
    }

    bool InputManager::Restart(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            return true;
        }
        return false;
    }

    sf::Vector2i InputManager::GetMousePoint(sf::RenderWindow &window){
        return sf::Mouse::getPosition(window);
    }
}