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
        (srand(time(NULL)));
        if(rand()%3==0){
            sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle1"));
            sprite.setPosition(this->_data->window.getSize().x, 420);
            ObstacleSprites.push_back(sprite);
        }
        else if(rand()%3==1){
            sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle2"));
            sprite.setPosition(this->_data->window.getSize().x, 420);
            ObstacleSprites.push_back(sprite);
        }
        else if(rand()%3==2){
            sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle3"));
            sprite.setPosition(this->_data->window.getSize().x, 420);
            ObstacleSprites.push_back(sprite);
        }
    }

    void Obstacle::MoveObstacles(float dt){
        if(clock.getElapsedTime().asSeconds()>7)
            speedMultiply = 1;
        for(unsigned short int i=0; i<ObstacleSprites.size(); i++){
            if(ObstacleSprites.at(i).getPosition().x<0 - ObstacleSprites.at(i).getGlobalBounds().width){
                ObstacleSprites.erase(ObstacleSprites.begin()+i);
            }
            else{
                sf::Vector2f position = ObstacleSprites.at(i).getPosition();
                float movement = (speedMultiply)+(OBSTACLE_SPEED*dt);
                ObstacleSprites.at(i).move(-movement,0);
                std::cout<<"Scoring-"<<movement<<std::endl;
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
        //sprite.setColor(sf::Color(0,0,0,0));
        ScoringSprites.push_back(sprite);
    }

    void Obstacle::MoveScoring(float dt){
        if(clock.getElapsedTime().asSeconds()>7)
            speedMultiply = 1;
        for(unsigned short int i=0; i<ScoringSprites.size(); i++){
            if(ObstacleSprites.at(i).getPosition().x<0 - ObstacleSprites.at(i).getGlobalBounds().width){
                ScoringSprites.erase(ScoringSprites.begin()+i);
            }
            else{
                sf::Vector2f position = ObstacleSprites.at(i).getPosition();
                float movement = (speedMultiply*2)+((OBSTACLE_SPEED*2)*dt);
                ScoringSprites.at(i).move(-movement,0);
                std::cout<<movement<<std::endl;
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