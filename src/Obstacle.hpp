#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include <time.h>
#include <stdlib.h>

namespace S{
    class Obstacle{
        public:
            int num_obstacles = 0;
            Obstacle(GameDataRef data);
            void Spawn();
            void MoveObstacles(float dt, float speed );
            void Destroy( );
            void DrawObstacle();
            std::vector<sf::Sprite> ObstacleSprites;

        private:
            GameDataRef _data;
    };
}