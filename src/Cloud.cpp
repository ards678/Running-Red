#include "Cloud.hpp"
#include "DEFINITIONS.hpp"

namespace S{
    Cloud::Cloud(GameDataRef data): _data(data){
        sf::Sprite sprite(_data->assets.GetTexture("Cloud"));
        sf::Sprite sprite2(_data->assets.GetTexture("Cloud"));

        sprite.setPosition(0,_data->window.getSize().y-sprite.getGlobalBounds().height-133);
        sprite2.setPosition(sprite.getGlobalBounds().width,_data->window.getSize().y-sprite2.getGlobalBounds().height-133);

        _CloudSprite.push_back(sprite);
        _CloudSprite.push_back(sprite2);
    }

    void Cloud::MoveCloud(float dt){
        for(unsigned short int i=0; i<_CloudSprite.size(); i++){
            float movement = CLOUD_SPEED*dt;
            _CloudSprite.at(i).move(-movement,0.0f);
            if(_CloudSprite.at(i).getPosition().x<0-_CloudSprite.at(i).getGlobalBounds().width){
                sf::Vector2f position(_data->window.getSize().x, _CloudSprite.at(i).getPosition().y);
                _CloudSprite.at(i).setPosition(position);
            }
        }
    }

    void Cloud::DrawCloud(){
        for(unsigned short int i=0; i<_CloudSprite.size(); i++){
            _data->window.draw(_CloudSprite.at(i));
        }
    }
}