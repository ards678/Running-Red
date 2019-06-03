#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "GameState.hpp"

namespace S{
    class GameOverState : public State{
        public:
            GameOverState(GameDataRef data, int score);

            void Init();
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private:
            GameDataRef _data;
            int _score, _highScore;

            sf::Sprite _background;

            sf::Text _scoreText;
            sf::Text _highScoreText;

            int gameState;
    };
}