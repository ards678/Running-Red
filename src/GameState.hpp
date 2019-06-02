#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Obstacle.hpp"
#include "Ground.hpp"
#include "Game.hpp"

namespace S{
    class GameState : public State{
        public:
            GameState(GameDataRef data);

            void Init();
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private:
            GameDataRef _data;

            sf::Sprite _background;
            sf::Sprite _player;
            sf::Sprite _cloud;
            sf::Sprite _ground;
            //sf::Sprite _exitButton;

            int gameState;
            Obstacle *obstacle;
            Ground *ground;
            sf::Clock clock;
    };
}