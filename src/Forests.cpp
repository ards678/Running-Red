#include "Forests.hpp"
#include "DEFINITIONS.hpp"

namespace S{
    Forests::Forests(GameDataRef data): _data(data){
        sf::Sprite sprite(_data->assets.GetTexture("Forests"));
        sf::Sprite sprite2(_data->assets.GetTexture("Forests"));

        sprite.setPosition(0,_data->window.getSize().y-sprite.getGlobalBounds().height-133);
        sprite2.setPosition(sprite.getGlobalBounds().width,_data->window.getSize().y-sprite2.getGlobalBounds().height-133);

        _ForestSprite.push_back(sprite);
        _ForestSprite.push_back(sprite2);
    }

    void Forests::MoveForests(float dt){
        for(unsigned short int i=0; i<_ForestSprite.size(); i++){
            float movement = FOREST_SPEED*dt;
            _ForestSprite.at(i).move(-movement,0.0f);
            if(_ForestSprite.at(i).getPosition().x<0-_ForestSprite.at(i).getGlobalBounds().width){
                sf::Vector2f position(_data->window.getSize().x, _ForestSprite.at(i).getPosition().y);
                _ForestSprite.at(i).setPosition(position);
            }
        }
    }

    void Forests::DrawForests(){
        for(unsigned short int i=0; i<_ForestSprite.size(); i++){
            _data->window.draw(_ForestSprite.at(i));
        }
    }
}
