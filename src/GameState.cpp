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
		if (!deathSoundBuffer.loadFromFile(DEATH_AUDIO))
		{

		}
        if (!runMusicBuffer.loadFromFile(RUN_MUSIC_AUDIO))
		{

		}

        runMusic.setBuffer(runMusicBuffer);
		deathSound.setBuffer(deathSoundBuffer);

        gameState = STATE_PLAYING;
        this->_data->assets.LoadTexture("Game Background", GAME_STATIC_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Night Background", "Content/nightbackdrop.png");
        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
        this->_data->assets.LoadTexture("Mountain", GAME_MOUNTAIN);
        _data->assets.LoadTexture("Night Mountain", "Content/night mountain.png");
        _mountain.setTexture(this->_data->assets.GetTexture("Mountain"));
        _mountain.setPosition(sf::Vector2f(0,125));

        _data->assets.LoadTexture("Obstacle1", GAME_OBSTACLE1);
        _data->assets.LoadTexture("Obstacle2", GAME_OBSTACLE2);
        _data->assets.LoadTexture("Obstacle3", GAME_OBSTACLE3);
        _data->assets.LoadTexture("Ground", GAME_GROUND);
        _data->assets.LoadTexture("Night Ground", "Content/nightground.png");
        _data->assets.LoadTexture("Forests", FOREST_PATH);
        _data->assets.LoadTexture("Night Forests", "Content/nightforests.png");
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
        forests = new Forests(_data);
        nightforests = new NightForests(_data);

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

                }
            }
            else if(_data->input.Slide()){
                if(GameStates::eGameOver != _gameState){
                    _gameState = GameStates::ePlaying;
                    red->Slide();
                    //jumpSound.play();
                }
            }
        }
    }

    void GameState::Update(float dt){
        if(GameStates::eGameOver != _gameState){
            //runSound.setLoop(true);
            //runSound.play();
            //runSound.setVolume(50);
            runMusic.setLoop(true);
            runMusic.play();
            red->Animate(dt);
            //if(score<3){
                forests->MoveForests(dt);
            /*}
            else{
                nightforests->MoveNightForests(dt);
            }*/
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
                    scoringSprites.erase(scoringSprites.begin()+i);
                }
            }
        }

        if(GameStates::eGameOver == _gameState){
                this->_data->machine.AddState(StateRef(new GameOverState(_data, score)), true);
                deathSound.play();
        }
    }

    void GameState::Draw(float dt){
        int flag=0;
        /*if(score>1 && score%5==0 && flag==0){
            _background.setTexture(this->_data->assets.GetTexture("Night Backdrop"));
            _mountain.setTexture(this->_data->assets.GetTexture("Night Mountain"));
            flag=1;
        }*/
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_mountain);

        /*if(score>3){
            nightforests->DrawNightForests();
        }
        else{*/
            forests->DrawForests();
        //}
        ground->DrawGround();
        obstacle->DrawObstacle();
        obstacle->DrawScoring();
        red->Draw();
        hud->Draw();

        this->_data->window.display();
    }
}