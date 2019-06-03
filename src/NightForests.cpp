#include "NightForests.hpp"
#include "DEFINITIONS.hpp"

namespace S{
    NightForests::NightForests(GameDataRef data): _data(data){
        sf::Sprite sprite(_data->assets.GetTexture("Night Forests"));
        sf::Sprite sprite2(_data->assets.GetTexture("Night Forests"));

        sprite.setPosition(0,_data->window.getSize().y-sprite.getGlobalBounds().height-133);
        sprite2.setPosition(sprite.getGlobalBounds().width,_data->window.getSize().y-sprite2.getGlobalBounds().height-133);

        _NightForestSprite.push_back(sprite);
        _NightForestSprite.push_back(sprite2);
    }

    void NightForests::MoveNightForests(float dt){
        for(unsigned short int i=0; i<_NightForestSprite.size(); i++){
            float movement = FOREST_SPEED*dt;
            _NightForestSprite.at(i).move(-movement,0.0f);
            if(_NightForestSprite.at(i).getPosition().x<0-_NightForestSprite.at(i).getGlobalBounds().width){
                sf::Vector2f position(_data->window.getSize().x, _NightForestSprite.at(i).getPosition().y);
                _NightForestSprite.at(i).setPosition(position);
            }
        }
    }

    void NightForests::DrawNightForests(){
        for(unsigned short int i=0; i<_NightForestSprite.size(); i++){
            _data->window.draw(_NightForestSprite.at(i));
        }
    }
}
