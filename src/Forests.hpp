#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace S{
    class Forests{
        public:
            Forests(GameDataRef data);

            void MoveForests(float dt);
            void DrawForests();
        private:
            GameDataRef _data;
            std::vector<sf::Sprite> _ForestSprite;
    };

}