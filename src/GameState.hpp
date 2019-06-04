#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Ground.hpp"
#include "Obstacle.hpp"
#include "Player.hpp"
#include "State.hpp"
#include "Forests.hpp"

namespace S {
class GameState : public State {
 public:
  GameState(GameDataRef data);

  void Init();
  void HandleInput();
  void Update(float dt);
  void Draw(float dt);
  bool gameOver = false;

 private:
  int score;
  int player_pos_x;
  GameDataRef _data;

  sf::Sprite _background;
  Player *player;
  sf::Sprite _player;
  sf::Sprite _cloud;
  sf::Sprite _ground;
  // sf::Sprite _exitButton;

Forests *forests;
  bool beginIsMinused;
  int gameState;
  Obstacle *obstacle;
  Ground *ground;
  sf::Clock clock;
  sf::Clock gameClock;
};
}  // namespace S