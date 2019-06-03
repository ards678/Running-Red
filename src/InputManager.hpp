#pragma once

#include <SFML/Graphics.hpp>

namespace S{
    class InputManager{
        public:
            InputManager();
            ~InputManager();

            bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf:: RenderWindow &window);
            bool Jump();
            bool Slide();
            bool Restart();
            sf::Vector2i GetMousePoint(sf::RenderWindow &window);
    };
}