#include "Ground.hpp"
#include "DEFINITIONS.hpp"

namespace S{
    Ground::Ground(GameDataRef data): _data(data){
        sf::Sprite sprite(_data->assets.GetTexture("Ground"));
        sf::Sprite sprite2(_data->assets.GetTexture("Ground"));

        sprite.setPosition(0,_data->window.getSize().y-sprite.getGlobalBounds().height+70);
        sprite2.setPosition(sprite.getGlobalBounds().width,_data->window.getSize().y-sprite2.getGlobalBounds().height+70);

        _GroundSprite.push_back(sprite);
        _GroundSprite.push_back(sprite2);
    }

    void Ground::MoveGround(float dt){
        for(unsigned short int i=0; i<_GroundSprite.size(); i++){
            float movement = OBSTACLE_SPEED*dt;
            _GroundSprite.at(i).move(-movement,0.0f);
            if(_GroundSprite.at(i).getPosition().x<0-_GroundSprite.at(i).getGlobalBounds().width){
                sf::Vector2f position(_data->window.getSize().x, _GroundSprite.at(i).getPosition().y);
                _GroundSprite.at(i).setPosition(position);
            }
        }
    }

    void Ground::DrawGround(){
        for(unsigned short int i=0; i<_GroundSprite.size(); i++){
            _data->window.draw(_GroundSprite.at(i));
        }
    }
}
