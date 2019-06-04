#pragma once
#include "Game.hpp"
// #include "Collision.hpp"
// #include "Collision.h"
using namespace std;
using namespace sf;

namespace S {
class Player {
 public:
  Player(GameDataRef data);
  void initializePlayer(String, IntRect, Vector2f, float, int, int);
  void animate(float dt,float speed);
  void jump();
  bool isHit(Sprite s);
  // void slide();
  Music jumpSound;
  Sprite sprite;
  int increment;
  float speed;
  float x, y;

 private:
  GameDataRef _data;
  void updatePosition(float dt);
  Texture t;
  IntRect rect;
  Clock clock, c;
  float defaultPos;
  float velocity = 0, gravity = 100;
  float frames;
  int bounds;
};
};  // namespace S
