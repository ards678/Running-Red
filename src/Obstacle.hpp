#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace S{
    class Obstacle{
        public:
            int num_obstacles = 0;
            Obstacle(GameDataRef data);
            void Spawn();
            void MoveObstacles(float dt, float speed);
            void Destroy( );
            void DrawObstacle();

        private:
            GameDataRef _data;
            std::vector<sf::Sprite> ObstacleSprites;
    };
}