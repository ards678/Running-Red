#include "Main.hpp"
// #include "Collision.hpp"

using namespace std;
using namespace sf;

class Cloud {
 public:
  Texture texture;
  Sprite sprite;
  Vector2f pos;
  int num = 0;
  float xVel = 0;
  Cloud(string path, Vector2f pos, int num) {
    texture.loadFromFile(path);
    this->pos = pos;
    this->num = num;
    pos.x/=2;
    pos.y*=1.5;

    // if (num % 2 == 0){

    //     sprite.setOrigin( sprite.getLocalBounds().width,0.);
    //     sprite.scale(-1, 1);

    // }
    // move();
  };

  void move() { xVel = -11; };
  void stop() { xVel = 0; };
  Sprite drawCloud(float speed, float dt) {

    sprite.setTexture(texture);
    sprite.setPosition(pos);
    // texture.
    xVel = speed;
    pos.x += xVel * dt * 0.25;

    // cout<<"otoy"<<speed<<endl;
    if (pos.x <= - 1280) teleport();

    return sprite;
  };

  void teleport() { pos.x = 1280 ; };
};