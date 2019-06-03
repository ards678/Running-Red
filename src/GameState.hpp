#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Obstacle.hpp"
#include "Ground.hpp"
#include "Forests.hpp"
#include "NightForests.hpp"
#include "Red.hpp"
#include "Game.hpp"
#include "CollisionChecker.hpp"
#include "HUD.hpp"

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
            sf::Sprite _mountain;
            sf::Sprite _player;
            sf::Sprite _cloud;
            sf::Sprite _ground;
            //sf::Sprite _exitButton;

            int gameState;
            Obstacle *obstacle;
            Ground *ground;
            Forests *forests;
            NightForests *nightforests;
            Red *red;
            HUD *hud;
            Collision collision;
            sf::Clock clock;
            sf::Clock timer;
            sf::Text currentScore;


            sf::SoundBuffer jumpSoundBuffer;
            sf::SoundBuffer deathSoundBuffer;
            sf::SoundBuffer runMusicBuffer;


            sf::Sound jumpSound;
            sf::Sound deathSound;
            sf::Sound runMusic;

            int _gameState, score=0, highScore=0;
    };
}