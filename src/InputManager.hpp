#pragma once

#include <SFML/Graphics.hpp>

namespace S{
    class InputManager{
        public:
            InputManager();
            ~InputManager();

            bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf:: RenderWindow &window);
            bool Jump(sf::Sprite object);
            bool Slide(sf::Sprite object);
            bool Restart(sf::Sprite object);
            sf::Vector2i GetMousePoint(sf::RenderWindow &window);
    };
}