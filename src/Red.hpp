#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace S{
    class Red{
        public:
            Red(GameDataRef data);
            void Draw();
            void Animate(float dt);
            void Update(float dt);
            void Jump();
            void Slide();

            const sf::Sprite &GetSprite() const;

        private:
            GameDataRef _data;
            sf::Sprite _RedSprite;
            std::vector<sf::Texture> _animationFrames;

            unsigned int _animationIterator;

            sf::Clock clock;
            sf::Clock movement;

            int current;
            float velocity=0, y;
    };
}