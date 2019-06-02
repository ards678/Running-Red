#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace S{
    class Obstacle{
        public:
            Obstacle(GameDataRef data);
            void Spawn();
            void MoveObstacles(float dt);
            void DrawObstacle();

        private:
            GameDataRef _data;
            std::vector<sf::Sprite> ObstacleSprites;
    };
}