
#include "GameState.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include "DEFINITIONS.hpp"
// #include "Player.hpp"
using namespace std;
using namespace sf;
namespace S {
GameState::GameState(GameDataRef data) : _data(data) {}

void GameState::Init() {
  gameState = STATE_PLAYING;
  this->_data->assets.LoadTexture("Game Background",
                                  GAME_STATIC_BACKGROUND_FILEPATH);
  _background.setTexture(this->_data->assets.GetTexture("Game Background"));

  _data->assets.LoadTexture("Obstacle1", GAME_OBSTACLE1);
  _data->assets.LoadTexture("Ground", GAME_GROUND);

  obstacle = new Obstacle(_data);
  ground = new Ground(_data);
  player = new Player(_data);

  player->initializePlayer("content/playerspritesheet.png",
                           IntRect(0, 0, 128, 128), Vector2f(30, 310), 0.05,
                           1664, 128);
  player_pos_x = player->x;
  // POSX = player->x
  score = 0;

  bool beginIsMinused = false;
}

void GameState::HandleInput() {
  sf::Event event;
  while (this->_data->window.pollEvent(event)) {
    if (sf::Event::Closed == event.type) {
      this->_data->window.close();
    }
    if (_data->input.Jump(player->sprite)) {
      //   if (GameStates::eGameOver != _gameState) {
      //     _gameState = GameStates::ePlaying;
      player->jump();
      //   }
    }
    if (sf::Keyboard::Escape == event.type) {
      this->_data->window.close();
    }
  }
}

void GameState::Update(float dt) {
  if (gameOver) {
    cout << "gameover!!!!!!!!" << endl;
  }

  else {
    float elapsed = gameClock.getElapsedTime().asSeconds();

    float speed = 530 + 40 * sqrt(elapsed);
    obstacle->MoveObstacles(dt, speed);
    // obstacle->Spawn();
    player->animate(dt, speed);
    ground->MoveGround(dt, speed);
    cout << "time: " << elapsed << "score: " << score << endl;
    // bool incrementScore = false;
    for (auto i = obstacle->ObstacleSprites.begin();
         i != obstacle->ObstacleSprites.end(); i++) {
             gameOver = player->isHit(*i);
      if (i == obstacle->ObstacleSprites.begin() && !beginIsMinused &&
          i->getPosition().x < player_pos_x) {
        score++;
        beginIsMinused = true;
        // player->sprite.getLo
      }
      // if (i->getPosition().x < player_pos_x && i = ) {
      //   if (!incrementScore) {
      //     score++;
      //     incrementScore = true;
      //   }
      // }
    }
    if (obstacle->ObstacleSprites.size() != 0) {
      if (obstacle->ObstacleSprites.begin()->getPosition().x < -50) {
        obstacle->Destroy();
        cout << "dest" << endl;
        beginIsMinused = false;
      }
    }

    srand(elapsed);
    if (clock.getElapsedTime().asSeconds() >
        8 * (1 / (1+elapsed)) + OBSTACLE_FREQUENCY +
            (pow(-1, rand() % 100) * (rand() % 5) * 0.2)) {
      obstacle->Spawn();
      clock.restart();
    }
  }
  //   if (clock.getElapsedTime().asSeconds() > 4) {
  //     obstacle->Destroy();
  //   }

  //   player->updatePosition();
}

void GameState::Draw(float dt) {
  this->_data->window.clear();
  this->_data->window.draw(this->_background);
  this->_data->window.draw(this->_player);
  this->_data->window.draw(this->player->sprite);
  this->_data->window.draw(this->_cloud);
  this->_data->window.draw(this->_ground);

  obstacle->DrawObstacle();
  ground->DrawGround();

  this->_data->window.display();
}
}  // namespace S