#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace S{
    class Obstacle{
        public:
            Obstacle(GameDataRef data);
            void Spawn();
            void SpawnScoring();
            void MoveObstacles(float dt);
            void MoveScoring(float dt);
            void DrawObstacle();
            void DrawScoring();
            bool isHit(sf::Sprite object);

            const std::vector<sf::Sprite> &GetSprite() const;
            std::vector<sf::Sprite> &GetScoringSprites();

        private:
            GameDataRef _data;
            std::vector<sf::Sprite> ObstacleSprites;
            std::vector<sf::Sprite> ScoringSprites;

            sf::Sprite sprite;

            sf::Clock clock;

            float speedMultiply=0;
    };
}