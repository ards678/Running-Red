#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace S{
    class Ground{
        public:
            Ground(GameDataRef data);

            void MoveGround(float dt);
            void DrawGround();
        private:
            GameDataRef _data;
            std::vector<sf::Sprite> _GroundSprite;
    };

}