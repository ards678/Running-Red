#include <cmath>
#include <sstream>
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace S{
    GameState::GameState(GameDataRef data): _data(data){

    }

    void GameState::Init(){
        if (!runSoundBuffer.loadFromFile(RUNNING_AUDIO))
		{

		}

		if (!jumpSoundBuffer.loadFromFile(JUMPING_AUDIO))
		{

		}

		if (!deathSoundBuffer.loadFromFile(DEATH_AUDIO))
		{

		}

		runSound.setBuffer(runSoundBuffer);
		jumpSound.setBuffer(jumpSoundBuffer);
		deathSound.setBuffer(deathSoundBuffer);

        gameState = STATE_PLAYING;
        this->_data->assets.LoadTexture("Game Background", GAME_STATIC_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));

        _data->assets.LoadTexture("Obstacle1", GAME_OBSTACLE1);
        _data->assets.LoadTexture("Ground", GAME_GROUND);
        _data->assets.LoadTexture("Frame 1", RED_FRAME_1);
        _data->assets.LoadTexture("Frame 2", RED_FRAME_2);
        _data->assets.LoadTexture("Frame 3", RED_FRAME_3);
        _data->assets.LoadTexture("Frame 4", RED_FRAME_4);
        _data->assets.LoadTexture("Frame 5", RED_FRAME_5);
        _data->assets.LoadTexture("Frame 6", RED_FRAME_6);
        _data->assets.LoadTexture("Frame 7", RED_FRAME_7);
        _data->assets.LoadTexture("Frame 8", RED_FRAME_8);
        _data->assets.LoadTexture("Frame 9", RED_FRAME_9);
        _data->assets.LoadTexture("Frame 10", RED_FRAME_10);
        _data->assets.LoadTexture("Frame 11", RED_FRAME_11);
        _data->assets.LoadTexture("Frame 12", RED_FRAME_12);
        _data->assets.LoadTexture("Frame 13", RED_FRAME_13);
        _data->assets.LoadTexture("Frame 14", RED_FRAME_14);
        _data->assets.LoadTexture("Jump 1", RED_JUMP_1);
        _data->assets.LoadTexture("Jump 2", RED_JUMP_2);
        _data->assets.LoadTexture("Slide 1", RED_SLIDE_1);
        _data->assets.LoadTexture("Slide 2", RED_SLIDE_2);
        _data->assets.LoadTexture("Scoring", SCORING_PATH);
        _data->assets.LoadFont("font", FONT_PATH);

        obstacle = new Obstacle(_data);
        ground = new Ground(_data);
        red = new Red(_data);
        hud = new HUD(_data);

        _gameState = GameStates::eReady;
        score = 0;
        hud->UpdateScore(score);
        //currentScore("Score: 0", font, 24);
        //currentScore.setFillcolor(Color(0,0,0,0));
        currentScore.setPosition(640,20);
    }

    void GameState::HandleInput(){
        sf::Event event;
        while(this->_data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                this->_data->window.close();
            }
            if(_data->input.Jump()){
                if(GameStates::eGameOver != _gameState){
                    _gameState = GameStates::ePlaying;
                    red->Jump();
                    jumpSound.play();
                }
            }
            else if(_data->input.Slide()){
                if(GameStates::eGameOver != _gameState){
                    _gameState = GameStates::ePlaying;
                    red->Slide();
                    jumpSound.play();
                }
            }
        }
    }

    void GameState::Update(float dt){
        if(GameStates::eGameOver != _gameState){
            red->Animate(dt);
            obstacle->MoveObstacles(dt);
            obstacle->MoveScoring(dt);
            ground->MoveGround(dt);
        }
            if(GameStates::ePlaying==_gameState){
                obstacle->MoveObstacles(dt);
                if(clock.getElapsedTime().asSeconds()>OBSTACLE_FREQUENCY){
                    obstacle->Spawn();
                    obstacle->SpawnScoring();
                    clock.restart();
                }
            }
                red->Update(dt);

                std::vector<sf::Sprite> obstacleSprites = obstacle->GetSprite();
                for(int i=0; i<obstacleSprites.size(); i++){
                    if(collision.CheckSpriteCollision(red->GetSprite(),0.625f,obstacleSprites.at(i),1.0f)){
                        _gameState = GameStates::eGameOver;
                        clock.restart();
                    }
                }
            if(GameStates::ePlaying == _gameState){
                std::vector<sf::Sprite> &scoringSprites = obstacle->GetScoringSprites();
                for(int i=0; i<scoringSprites.size(); i++){
                    if(collision.CheckSpriteCollision(red->GetSprite(),0.625f,scoringSprites.at(i),1.0f)){
                        score++;
                        hud->UpdateScore(score);
                        std::cout<<"score: "<<score<<std::endl;
                        scoringSprites.erase(scoringSprites.begin()+i);
                    }
                }
            }

        if(GameStates::eGameOver == _gameState){
            if(clock.getElapsedTime().asMilliseconds()>GAME_OVER_TIME){
                this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
                deathSound.play();
            }
        }
    }

    void GameState::Draw(float dt){
        this->_data->window.clear();
        this->_data->window.draw(this->_background);

        obstacle->DrawObstacle();
        obstacle->DrawScoring();
        ground->DrawGround();
        red->Draw();
        hud->Draw();

        this->_data->window.display();
    }
}