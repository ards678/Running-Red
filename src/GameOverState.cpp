
#include <sstream>
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>
#include <fstream>

namespace S{
    GameOverState::GameOverState(GameDataRef data, int score): _data(data), _score(score){

    }

    void GameOverState::Init(){
        std::ifstream readFile;
        readFile.open("Content/hiscore.txt");
        if(readFile.is_open()){
            while(!readFile.eof()){
                readFile>>_highScore;
            }
        }
        readFile.close();
        std::ofstream writeFile("Content/hiscore.txt");
        if(writeFile.is_open()){
            if(_score>_highScore){
                _highScore = _score;
            }
            writeFile<<_highScore;
        }
        writeFile.close();

        _scoreText.setFont(this->_data->assets.GetFont("font"));
        _scoreText.setString("Last Attempt: "+std::to_string(_score));
        _scoreText.setCharacterSize(56);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setPosition(sf::Vector2f(300, 320));

        _highScoreText.setFont(this->_data->assets.GetFont("font"));
        _highScoreText.setString("Best Attempt: "+std::to_string(_highScore));
        _highScoreText.setCharacterSize(56);
        _highScoreText.setFillColor(sf::Color::Yellow);
        _highScoreText.setPosition(sf::Vector2f(300, 390));

        gameState = STATE_DEAD;
        _data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
    }

    void GameOverState::HandleInput(){
        sf::Event event;
        while(this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }
            if(_data->input.Restart()){
                _data->machine.AddState(StateRef(new GameState(_data)),true);
            }

        }
    }

    void GameOverState::Update(float dt){

    }

    void GameOverState::Draw(float dt){
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.draw(_scoreText);
        this->_data->window.draw(_highScoreText);

        this->_data->window.display();
    }
}