#include "Main.hpp"
#include <cmath>
#include <fstream>
#include "Cloud.h"
#include "Ground.h"
#include "Mountain.h"
#include "Obstacles.hpp"
#include "Sprite.hpp"
#include "background.hpp"

using namespace std;
using namespace sf;

int main() {
  RenderWindow window(VideoMode(1280, 720), "Dagan-dagan");
  window.setFramerateLimit(60);
  Background bg("content/backdrop.png");
  Background mn("content/static mountain.png");
  Background floor("content/ground.png");
  Clock clock;
  // Texture floorTexture;

  // floorTexture.loadFromFile("content/ground.png");

  mn.sprite.setPosition(Vector2f(0, 100));
  floor.sprite.setPosition(Vector2f(0, 444));
  Background cl("content/cloud1.png");
  Ground ground1("content/ground.png", Vector2f(0.f, 440.f), 1);
  Ground ground2("content/ground.png", Vector2f(1280.f, 440.f), 2);
  Ground ground3("content/ground.png", Vector2f(2560.f, 440.f), 3);
  Ground ground4("content/ground.png", Vector2f(3840.f, 440.f), 4);
  Ground ground5("content/ground.png", Vector2f(3840.f + 1280, 440.f), 5);
  Ground ground6("content/ground.png", Vector2f(3840.f + (1280 * 2), 440.f), 5);

  Cloud cloud1("content/cloud1.png", Vector2f(0.f, 140.f), 1);
  Cloud cloud2("content/cloud1.png", Vector2f(1280.f, 140.f), 2);
  Cloud cloud3("content/cloud1.png", Vector2f(2560.f, 140.f), 3);
  Cloud cloud4("content/cloud1.png", Vector2f(3840.f, 140.f), 4);
  Cloud cloud5("content/cloud1.png", Vector2f(3840.f + 1280, 140.f), 5);
  Cloud cloud6("content/cloud1.png", Vector2f(3840.f + (1280 * 2), 140.f), 6);

  Mountain mount1("content/static mountain.png", Vector2f(0.f, 140.f), 1);
  Mountain mount2("content/cool.png", Vector2f(1280.f, 140.f), 2);
  Mountain mount3("content/static mountain.png", Vector2f(2560.f, 140.f), 3);
  Mountain mount4("content/cool.png", Vector2f(3840.f, 140.f), 4);
  Mountain mount5("content/static mountain.png", Vector2f(3840.f + 1280, 140.f),
                  5);
  Mountain mount6("content/cool.png", Vector2f(3840.f + (1280 * 2), 140.f), 6);

  SpriteAnimate character("content/playerspritesheet.png",
                          IntRect(0, 0, 128, 128), Vector2f(400, 380), 0.05,
                          1664, 128);
  character.sprite.setOrigin(Vector2f(64, 64));
  int score = 0, i = 0, hiScore = 0;
  float speed = -7;
  float spawn = 2.5;
  Clock game, scr, jumpClock;
  bool gameOn = true;
  Font font;
  font.loadFromFile("content/Fipps-Regular.otf");
  Text currentScore("Score: 0", font, 20);
  Text highScore("High Score: ", font, 20);
  Text gameOver("Game Over\n", font, 90), finalScore("10", font, 140);
  finalScore.setPosition(640, 420);
  gameOver.setPosition(640, 350);
  gameOver.setOrigin(gameOver.getLocalBounds().width / 2.0f,
                     gameOver.getLocalBounds().height / 2.0f);
  highScore.setPosition(10, 10);
  highScore.setFillColor(Color(0, 0, 0));

  ifstream readFile;
  readFile.open("Content/hiscore.txt");
  if (readFile.is_open()) {
    while (!readFile.eof()) {
      readFile >> hiScore;
    }
  }
  readFile.close();
  highScore.setString("High Score: " + to_string(hiScore));

  currentScore.setFillColor(Color(0, 0, 0));
  currentScore.setPosition(10, 40);
  vector<Obstacle> ob;
  Obstacle t[] = {Obstacle("content/obstacle1.png", 1),
                  Obstacle("content/obstacle2.png", 1),
                  Obstacle("content/obstacle3.png", 1),
                  Obstacle("content/Ship4.png", 2)};

  Music back, jumpSound, run, gameover;
  if (!back.openFromFile("content/bg.ogg")) return EXIT_FAILURE;
  if (!run.openFromFile("content/run.ogg")) return EXIT_FAILURE;
  if (!jumpSound.openFromFile("content/jump.ogg")) return EXIT_FAILURE;
  if (!gameover.openFromFile("content/gameover.ogg")) return EXIT_FAILURE;
  gameover.setVolume(50);

  run.setLoop(true);
  run.play();
  run.setVolume(50);
  back.setLoop(true);
  back.play();

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
      if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) window.close();
      if (event.type == Event::KeyPressed &&
          (event.key.code == Keyboard::Up ||
           event.key.code == Keyboard::Space)) {
        character.jump();
        // jumpSound.play();
        if (!gameOn) {
          score = 0;
          i = 0;
          character.increment = 128;
          gameOn = true;
          ob.clear();
        }
      }
      // if(event.type==Event::KeyPressed && event.key.code==Keyboard::Down)
      //     character.slide();
    }
    if (jumpClock.getElapsedTime().asSeconds() > 0.8f) {
      jumpSound.stop();
      jumpClock.restart();
    }
    srand(time(NULL) * (score + 3));
    if (score > 10) spawn = 1.8 + (pow(-1, rand() % 2) * 0.2 * (rand() % 5));
    if (score > 20) spawn = 1.0 + (pow(-1, rand() % 3) * 0.2 * (rand() % 5));
    if (score > 30) spawn = 0.7 + (pow(-1, rand() % 3) * 0.2 * (rand() % 5));
    if (game.getElapsedTime().asSeconds() > spawn) {
      if (gameOn) {
        srand(time(NULL));
        int random = (rand() % 4);
        ob.push_back(t[random]);
        score++;
      }
      game.restart();
    }
    float dt = clock.restart().asMilliseconds() / 10;
    currentScore.setString("Score: " + to_string(score));
    character.animate(dt);
    window.clear(Color(240, 240, 240));

    speed = -6 - (0.5 * score * log(4 + score));

    window.draw(bg.sprite);
    window.draw(mount1.drawMountain(speed, dt));
    window.draw(mount2.drawMountain(speed, dt));
    window.draw(mount3.drawMountain(speed, dt));
    window.draw(mount4.drawMountain(speed, dt));
    window.draw(mount5.drawMountain(speed, dt));
    window.draw(mount6.drawMountain(speed, dt));

    window.draw(cloud1.drawCloud(speed, dt));
    window.draw(cloud2.drawCloud(speed, dt));
    window.draw(cloud3.drawCloud(speed, dt));
    window.draw(cloud4.drawCloud(speed, dt));
    window.draw(cloud5.drawCloud(speed, dt));
    window.draw(cloud6.drawCloud(speed, dt));
    // window.draw(mn.sprite);
    // window.draw(floor.sprite);

    window.draw(character.sprite);
    cout << dt << endl;
    window.draw(ground1.drawGround(speed, dt));
    window.draw(ground2.drawGround(speed, dt));
    window.draw(ground3.drawGround(speed, dt));
    window.draw(ground4.drawGround(speed, dt));
    window.draw(ground5.drawGround(speed, dt));
    window.draw(ground6.drawGround(speed, dt));
    // window.draw();
    for (int k = ob.size() - 1; k >= 0; k--) {
      ob[k].update(dt);
      ob[k].speed = speed;
      cout << ob[k].speed << "haa" << speed << endl;
      // if(score > 10){
      //     ob[k].speed = -11;
      //     speed = -11;}
      // if(score > 20){
      //     ob[k].speed = -15;
      //     speed = -15;}
      // if(score > 30){
      //     ob[k].speed = -19;
      //     speed = -19;}
      window.draw(ob[k].sprite);
      if (ob[k].x < 0) ob.erase(ob.begin() + k);
      if (ob[k].isHit(character.sprite)) {
        character.increment = 0;
        ob[k].speed = 0;
        speed = -6 - (score * log(1 + score));
        gameOn = false;
        spawn = 2.5;
        if (scr.getElapsedTime().asSeconds() > 0.05f && i <= score) {
          finalScore.setString(to_string(i));
          finalScore.setOrigin(finalScore.getLocalBounds().width / 2.0f,
                               finalScore.getLocalBounds().height / 2.0f);
          scr.restart();
          i++;
        }
      }
    }
    if (!gameOn) {
      std::ofstream writeFile("Content/hiscore.txt");
      if (writeFile.is_open()) {
        if (score > hiScore) {
          hiScore = score;
        }
        writeFile << hiScore;
      }
      // cout << hiScore << endl;
      writeFile.close();
      highScore.setString("High Score: " + to_string(hiScore));

      window.draw(gameOver);
      currentScore.setString("");
      window.draw(finalScore);
      // ob.clear();
    }
    window.draw(highScore);
    window.draw(currentScore);
    window.display();
  }
  return EXIT_SUCCESS;
}
