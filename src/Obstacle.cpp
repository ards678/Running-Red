#include "DEFINITIONS.hpp"
#include "Obstacle.hpp"
#include "Collision.hpp"


namespace S{
    Obstacle::Obstacle(GameDataRef data): _data(data){
        texture=0;
    }
    void Obstacle::DrawObstacle(){
        for (unsigned short int i=0; i<ObstacleSprites.size(); i++){
            _data->window.draw(ObstacleSprites.at(i));
        }

    }

    void Obstacle::Spawn(int score){
        (srand(time(NULL)));
        if(rand()%5==0){
            sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle1"));
            sprite.setPosition(this->_data->window.getSize().x, 420);
            ObstacleSprites.push_back(sprite);
            textureCount.push_back(1);
        }
        else if(rand()%5==1){
            sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle2"));
            sprite.setPosition(this->_data->window.getSize().x+20, 395);
            ObstacleSprites.push_back(sprite);
            textureCount.push_back(1);
        }
        else if(rand()%5==2){
            sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle3"));
            sprite.setPosition(this->_data->window.getSize().x+20, 370);
            ObstacleSprites.push_back(sprite);
            textureCount.push_back(1);
        }
        if(rand()%5<=3){
            sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle5"));
            sprite.setPosition(this->_data->window.getSize().x+20, 300);
            ObstacleSprites.push_back(sprite);
            textureCount.push_back(2);
        }
        else if(rand()%5==4){
            sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle5"));
            sprite.setPosition(this->_data->window.getSize().x+20, 275);
            ObstacleSprites.push_back(sprite);
            textureCount.push_back(2);
        }
        if(score%5==0 && score>1)
            speedMultiply += 2.5;
    }

    int Obstacle::MoveObstacles(float dt){
        for(unsigned short int i=0; i<ObstacleSprites.size(); i++){
            if(ObstacleSprites.at(i).getPosition().x<0 - ObstacleSprites.at(i).getGlobalBounds().width){
                ObstacleSprites.erase(ObstacleSprites.begin()+i);
                textureCount.erase(textureCount.begin()+i);
            }
            else{
                float movement = speedMultiply+(OBSTACLE_SPEED*dt);
                ObstacleSprites.at(i).move(-movement,0);
                texture=textureCount.at(i);
                if(ObstacleSprites.at(i).getPosition().x<300)
                    return texture;
                else
                    return 0;
            }
        }
    }

    void Obstacle::DrawScoring(){
        for (unsigned short int i=0; i<ScoringSprites.size(); i++){
            _data->window.draw(ScoringSprites.at(i));
        }
    }

    void Obstacle::SpawnScoring(int score){
        sf::Sprite sprite(this->_data->assets.GetTexture("Scoring"));
        sprite.setPosition(this->_data->window.getSize().x+20, 0);
        //sprite.setColor(sf::Color(0,0,0,0));
        ScoringSprites.push_back(sprite);
        if(score%5==0 && score>1)
            speedMultiply += 2.5;
    }

    void Obstacle::MoveScoring(float dt){

        for(unsigned short int i=0; i<ScoringSprites.size(); i++){
            if(ScoringSprites.at(i).getPosition().x<0 - ScoringSprites.at(i).getGlobalBounds().width){
                ScoringSprites.erase(ScoringSprites.begin()+i);
            }
            else{
                float movement = speedMultiply+((OBSTACLE_SPEED)*dt);
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

}