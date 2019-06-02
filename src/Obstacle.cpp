#include "DEFINITIONS.hpp"
#include "Obstacle.hpp"
#include "Collision.hpp"


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
        sprite.setPosition(this->_data->window.getSize().x, 350);
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

    void Obstacle::DrawScoring(){
        for (unsigned short int i=0; i<ScoringSprites.size(); i++){
            _data->window.draw(ScoringSprites.at(i));
        }
    }

    void Obstacle::SpawnScoring(){
        sf::Sprite sprite(this->_data->assets.GetTexture("Scoring"));
        sprite.setPosition(this->_data->window.getSize().x, 0);
        sprite.setColor(sf::Color(0,0,0,0));
        ScoringSprites.push_back(sprite);
    }

    void Obstacle::MoveScoring(float dt){
        for(unsigned short int i=0; i<ScoringSprites.size(); i++){
            if(ObstacleSprites.at(i).getPosition().x<0 - ObstacleSprites.at(i).getGlobalBounds().width){
                ScoringSprites.erase(ScoringSprites.begin()+i);
            }
            else{
                sf::Vector2f position = ObstacleSprites.at(i).getPosition();
                float movement = (OBSTACLE_SPEED*2)*dt;
                ScoringSprites.at(i).move(-movement,0);
            }
        }
    }

    const std::vector<sf::Sprite> &Obstacle::GetSprite() const{
        return ObstacleSprites;
    }

    std::vector<sf::Sprite> &Obstacle::GetScoringSprites(){
        return ScoringSprites;
    }
    //bool Obstacle::isHit(sf::Sprite object){
    //    sf::Sprite sprite;
    //    return Collision::PixelPerfectTest(sprite, object);
    //}
}