
#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace S{
    GameState::GameState(GameDataRef data): _data(data){

    }

    void GameState::Init(){
        gameState = STATE_PLAYING;
        this->_data->assets.LoadTexture("Game Background", GAME_STATIC_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));

        _data->assets.LoadTexture("Obstacle1", GAME_OBSTACLE1);
        _data->assets.LoadTexture("Ground", GAME_GROUND);

        obstacle = new Obstacle(_data);
        ground = new Ground(_data);
    }

    void GameState::HandleInput(){
        sf::Event event;
        while(this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }
        }
    }

    void GameState::Update(float dt){
        obstacle->MoveObstacles(dt);
        ground->MoveGround(dt);
        if(clock.getElapsedTime().asSeconds()>OBSTACLE_FREQUENCY){
            obstacle->Spawn();
            clock.restart();
        }
    }

    void GameState::Draw(float dt){
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        //this->_data->window.draw(this->_player);
        //this->_data->window.draw(this->_cloud);
        //this->_data->window.draw(this->_ground);

        obstacle->DrawObstacle();
        ground->DrawGround();

        this->_data->window.display();
    }
}