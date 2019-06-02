#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace S{
    class MainMenuState : public State{
        public:
            MainMenuState(GameDataRef data);

            void Init();
            void HandleInput();
            void Update(float dt);
            void Draw(float dt);

        private:
            GameDataRef _data;

            sf::Sprite _background;
            sf::Sprite _playButton;
            sf::Sprite _creditsButton;
            sf::Sprite _aboutButton;
            sf::Sprite _exitButton;
    };
}