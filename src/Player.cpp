#import "Player.hpp"
#import <cmath>
#include "DEFINITIONS.hpp"

namespace S {
Player::Player(GameDataRef data)
    : _data(data){

      };

void Player::initializePlayer(String s, IntRect r, Vector2f f, float fr, int b,
                              int i) {
  rect = r;
  t.loadFromFile(s);
  sprite.setTexture(t);
  sprite.setTextureRect(rect);
  sprite.setPosition(f);
  x = f.x;
  defaultPos = y = f.y;
  frames = fr;
  bounds = b;
  increment = i;
}

void Player::animate(float dt, float speed) {
  updatePosition(dt);
  if (clock.getElapsedTime().asSeconds() > 10 * (1 / pow(speed, 0.9))) {
    if (rect.left >= bounds)
      rect.left = 0;
    else
      rect.left += increment;
    sprite.setTextureRect(rect);
    clock.restart();
  }
}

void Player::jump() {
  jumpSound.openFromFile("content/jump.ogg");
  jumpSound.play();
  if (sprite.getPosition().y == defaultPos) velocity = -25;
}

// void SpriteAnimate::slide(){
// 	velocity = 25;
// }

void Player::updatePosition(float dt) {
  velocity += gravity * dt;
  cout << "dt: " << dt << endl;
  y += velocity;
  if (y > defaultPos) y = defaultPos;
  if (y < 200) y = 200;
  if (y != defaultPos)
    frames = 0.15;
  else
    frames = 0.05;
  sprite.setPosition(x, y);
}

bool Player::isHit(Sprite s) {

  return (sprite.getPosition().x < s.getPosition().x + (0.7*s.getLocalBounds().width) &&
          sprite.getPosition().x + 0.7*sprite.getLocalBounds().width > s.getPosition().x &&
          sprite.getPosition().y < s.getPosition().y + 0.7*s.getLocalBounds().height &&
          0.7*sprite.getLocalBounds().height + sprite.getPosition().y> s.getPosition().y);
}
}  // namespace S
