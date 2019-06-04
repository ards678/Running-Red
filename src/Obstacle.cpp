#include "Obstacle.hpp"
#include "DEFINITIONS.hpp"

namespace S {
Obstacle::Obstacle(GameDataRef data) : _data(data) {}
void Obstacle::DrawObstacle() {
  for (unsigned short int i = 0; i < ObstacleSprites.size(); i++) {
    _data->window.draw(ObstacleSprites.at(i));
  }
}

void Obstacle::Spawn() {
  this->num_obstacles++;
  sf::Sprite sprite(this->_data->assets.GetTexture("Obstacle1"));
  sprite.setPosition(this->_data->window.getSize().x,
                     this->_data->window.getSize().y - 363);
  this->ObstacleSprites.push_back(sprite);
}

void Obstacle::Destroy() {
  this->ObstacleSprites.erase(ObstacleSprites.begin());
}

void Obstacle::MoveObstacles(float dt, float speed ) {
  for (unsigned short int i = 0; i < ObstacleSprites.size(); i++) {
    if (ObstacleSprites.at(i).getPosition().x <
        0 - ObstacleSprites.at(i).getGlobalBounds().width) {
      ObstacleSprites.erase(ObstacleSprites.begin() + i);
    } else {
      sf::Vector2f position = ObstacleSprites.at(i).getPosition();
      float movement = speed * dt;
      ObstacleSprites.at(i).move(-movement, 0);
    //   std::cout << "pos" << ObstacleSprites.at(i).getPosition().x
    //             << "pos: " << *player_pos_x << std::endl;
    //   if (ObstacleSprites.at(i).getPosition().x < -50) {
    //     Destroy();}

    //     std::cout << "dfah" <<*score<< std::endl;
    //   }
    }
  }
}
}  // namespace S