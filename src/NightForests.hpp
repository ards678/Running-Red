#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace S{
    class NightForests{
        public:
            NightForests(GameDataRef data);

            void MoveNightForests(float dt);
            void DrawNightForests();

        private:
            GameDataRef _data;
            std::vector<sf::Sprite> _NightForestSprite;
    };

}