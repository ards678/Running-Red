#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace S{
    class Cloud{
        public:
            Cloud(GameDataRef data);

            void MoveCloud(float dt);
            void DrawCloud();
        private:
            GameDataRef _data;
            std::vector<sf::Sprite> _CloudSprite;
    };

}