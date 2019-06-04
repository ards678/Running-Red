#include "Red.hpp"

namespace S{
    Red::Red(GameDataRef data): _data(data){
        if (!jumpSoundBuffer.loadFromFile(JUMPING_AUDIO))
		{

		}
        jumpSound.setBuffer(jumpSoundBuffer);
        if (!runSoundBuffer.loadFromFile(RUNNING_AUDIO))
		{

		}
        runSound.setBuffer(runSoundBuffer);
        _animationIterator=0;
        _animationFrames.push_back(_data->assets.GetTexture("Frame 1"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 2"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 3"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 4"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 5"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 6"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 7"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 8"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 8"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 10"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 11"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 12"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 13"));
        _animationFrames.push_back(_data->assets.GetTexture("Frame 14"));
        _animationFrames.push_back(_data->assets.GetTexture("Jump 1"));
        _animationFrames.push_back(_data->assets.GetTexture("Jump 2"));
        _animationFrames.push_back(_data->assets.GetTexture("Slide 1"));
        _animationFrames.push_back(_data->assets.GetTexture("Slide 2"));
        _RedSprite.setTexture(_animationFrames.at(_animationIterator));

        _RedSprite.setPosition(100,400);
        current = RED_RUNNING;
        runSound.play();

    }
    void Red::Draw(){
        _data->window.draw(_RedSprite);
    }
    void Red::Animate(float dt){
        if(clock.getElapsedTime().asSeconds()>ANIMATION_TIME/_animationFrames.size()){
            if(current == RED_JUMPING){
                _animationIterator=14;
            }
            else if(current == RED_SLIDING){
                _animationIterator=17;
            }
            else{
                if(_animationIterator<13){
                    _animationIterator++;
                }
                else{
                    _animationIterator=0;
                }
            }
            _RedSprite.setTexture(_animationFrames.at(_animationIterator));
            clock.restart();
        }
    }
    void Red::Update(float dt){
        std::cout<<y<<"---"<<velocity<<std::endl;
        y += velocity;
        if(current == RED_SLIDING){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                current == RED_RUNNING;
        }
        }

        if(y<150){
            y=150;
            //current = RED_JUMPING;
        }

        //if((current == RED_JUMPING || current == RED_RUNNING)){
        if(y>355){
                y=355;
                if((current == RED_JUMPING || current == RED_RUNNING)){
                    current = RED_RUNNING;
                    runSound.play();
                }
        }
        //}
        else{
            velocity += GRAVITY*dt;
        }
        _RedSprite.setPosition(25,y);
    }

    void Red::Jump(){
        if(y==355){
            velocity = -45;
            jumpSound.play();
            current = RED_JUMPING;
            runSound.stop();
        }
    }

    void Red::Slide(){
        if(y==355 && current == RED_RUNNING){
            current = RED_SLIDING;
            runSound.stop();
        }
        else{
            velocity = 3;
        }

    }

    const sf::Sprite &Red::GetSprite() const{
        return _RedSprite;
    }

}