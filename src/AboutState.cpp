
#include <sstream>
#include "AboutState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace S{
    AboutState::AboutState(GameDataRef data): _data(data){

    }

    void AboutState::Init(){
        this->_data->assets.LoadTexture("Background", "Content/About.png");

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));


    }

    void AboutState::HandleInput(){
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

    void AboutState::Update(float dt){

    }

    void AboutState::Draw(float dt){
        this->_data->window.clear();
        this->_data->window.draw(this->_background);

        this->_data->window.display();
    }
}