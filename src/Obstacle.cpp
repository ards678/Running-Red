#include "DEFINITIONS.hpp"
#include "Obstacle.hpp"

namespace S{
    Obstacle::Obstacle(GameDataRef data): _data(data){

    }
    void Obstacle::DrawObstacle(){
        for (unsigned short int i=0; i<ObstacleSprites.size(); i++){
            _data->window.draw(ObstacleSprites.at(i));
        }
    }

    void Obstacle::Spawn(){
        sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle1"));
        sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y-sprite.getGlobalBounds().height);
        ObstacleSprites.push_back(sprite);
    }

    void Obstacle::MoveObstacles(float dt){
        for(unsigned short int i=0; i<ObstacleSprites.size(); i++){
            if(ObstacleSprites.at(i).getPosition().x<0 - ObstacleSprites.at(i).getGlobalBounds().width){
                ObstacleSprites.erase(ObstacleSprites.begin()+i);
            }
            else{
                sf::Vector2f position = ObstacleSprites.at(i).getPosition();
                float movement = OBSTACLE_SPEED*dt;
                ObstacleSprites.at(i).move(-movement,0);
            }
        }

    }
}