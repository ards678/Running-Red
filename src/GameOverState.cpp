
#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace S{
    GameOverState::GameOverState(GameDataRef data): _data(data){

    }

    void GameOverState::Init(){
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

        this->_data->window.display();
    }
}