
#include <sstream>
#include "CreditsState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace S{
    CreditsState::CreditsState(GameDataRef data): _data(data){

    }

    void CreditsState::Init(){
        this->_data->assets.LoadTexture("Background", "Content/Credits.png");

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));


    }

    void CreditsState::HandleInput(){
        sf::Event event;
        while(this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }
            if(this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window)){
                _data->machine.AddState(StateRef(new MainMenuState(_data)),true);
            }
        }
    }

    void CreditsState::Update(float dt){

    }

    void CreditsState::Draw(float dt){
        this->_data->window.clear();
        this->_data->window.draw(this->_background);

        this->_data->window.display();
    }
}