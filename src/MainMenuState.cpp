
#include <sstream>
#include "MainMenuState.hpp"
#include "CreditsState.hpp"
#include "AboutState.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace S{
    MainMenuState::MainMenuState(GameDataRef data): _data(data){

    }

    void MainMenuState::Init(){
        this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
        this->_data->assets.LoadTexture("Credits Button", MAIN_MENU_CREDITS);
        this->_data->assets.LoadTexture("About Button", MAIN_MENU_ABOUT);

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));
        this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        this->_creditsButton.setTexture(this->_data->assets.GetTexture("Credits Button"));
        this->_aboutButton.setTexture(this->_data->assets.GetTexture("About Button"));

        this->_playButton.setPosition((SCREEN_WIDTH/2)-(this->_playButton.getGlobalBounds().width/2), (SCREEN_HEIGHT/1.75)-(this->_playButton.getGlobalBounds().height/6));
        this->_creditsButton.setPosition(0, (SCREEN_HEIGHT/1.25)-(this->_playButton.getGlobalBounds().height/3));
        this->_aboutButton.setPosition((SCREEN_WIDTH-175), (SCREEN_HEIGHT/1.25)-(this->_playButton.getGlobalBounds().height/2.25));

        if(!menuMusicBuffer.loadFromFile("Content/Intergalactic Odyssey.ogg")){

        }
        menuMusic.setBuffer(menuMusicBuffer);
        menuMusic.setLoop(true);
        menuMusic.play();
    }

    void MainMenuState::HandleInput(){
        sf::Event event;
        while(this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }
            if(this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window)){
                _data->machine.AddState(StateRef(new GameState(_data)),true);
                menuMusic.stop();
            }
            if(this->_data->input.IsSpriteClicked(this->_creditsButton, sf::Mouse::Left, this->_data->window)){
                _data->machine.AddState(StateRef(new CreditsState(_data)),true);
                menuMusic.stop();
            }
            if(this->_data->input.IsSpriteClicked(this->_aboutButton, sf::Mouse::Left, this->_data->window)){
                _data->machine.AddState(StateRef(new AboutState(_data)),true);
                menuMusic.stop();
            }
        }
    }

    void MainMenuState::Update(float dt){

    }

    void MainMenuState::Draw(float dt){
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_playButton);
        this->_data->window.draw(this->_creditsButton);
        this->_data->window.draw(this->_aboutButton);

        this->_data->window.display();
    }
}