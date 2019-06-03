#include "Red.hpp"

namespace S{
    Red::Red(GameDataRef data): _data(data){
        if (!jumpSoundBuffer.loadFromFile(JUMPING_AUDIO))
		{

		}
        jumpSound.setBuffer(jumpSoundBuffer);
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

        _RedSprite.setPosition(25,355);
        current = RED_RUNNING;
    }
    void Red::Draw(){
        _data->window.draw(_RedSprite);
    }
    void Red::Animate(float dt){
        if(clock.getElapsedTime().asSeconds()>ANIMATION_TIME/14){
            /*if(current == RED_JUMPING){
                _animationIterator=15;
            }
            else if(current == RED_SLIDING){
                _animationIterator=17;
            }
            else{*/
                if(_animationIterator<13){
                    _animationIterator++;
                }
                else{
                    _animationIterator=0;
                }
            //}
            _RedSprite.setTexture(_animationFrames.at(_animationIterator));
            clock.restart();
        }
    }
    void Red::Update(float dt){

        y += velocity;
        if(y<160){
            y=160;
        }

        if(y>355){
            y=355;
        }
        else{
            velocity += GRAVITY*dt;
        }
        /*if(_RedSprite.getPosition().y>=355){
            _RedSprite.setPosition(25,355);
            current = RED_RUNNING;
        }
        if(current == RED_SLIDING){
            _RedSprite.move(0,355);
        }
        if(current == RED_FALLING){
            _RedSprite.move(0,GRAVITY*dt);
        }*/
        //else if (current == RED_RUNNING){
        //    _RedSprite.move(0,355);
        //}
        if(current == RED_JUMPING){

            //_RedSprite.move(0,-JUMP_SPEED*dt);
        }
        /*if(movement.getElapsedTime().asSeconds()>JUMP_TIME){
            movement.restart();
            current = RED_FALLING;
            //velocity = -velocity;
        }*/
        _RedSprite.setPosition(25,y);
        //std::cout<<y<<"---"<<velocity<<std::endl;
    }

    void Red::Jump(){
        /*if(current == RED_RUNNING){
            movement.restart();
            current = RED_JUMPING;
        }*/if(y==355){
            velocity = -40;
            jumpSound.play();
        }
    }

    void Red::Slide(){
        //if(current == RED_RUNNING || current == RED_SLIDING){
            movement.restart();
            current = RED_SLIDING;
        //}
    }

    const sf::Sprite &Red::GetSprite() const{
        return _RedSprite;
    }

}