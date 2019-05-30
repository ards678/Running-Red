#include "Main.hpp"

using namespace std;
using namespace sf;

class SpriteAnimate{
public:
	SpriteAnimate(String ,IntRect, Vector2f, float, int, int);
	void animate(float dt);
	void jump( );
	//void slide();
	Music jumpSound;
	Sprite sprite;
	int increment;
	float x, y;
private:
	void updatePosition(float dt);
	Texture t;
	IntRect rect;
	Clock clock, c;
	float defaultPos;
	float velocity = 0, gravity = 1.2;
	float frames;
	int bounds;
};


SpriteAnimate::SpriteAnimate(String s, IntRect r, Vector2f f, float fr, int b, int i){
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

void SpriteAnimate::animate(float dt){
	if (clock.getElapsedTime().asSeconds() > frames){
		if (rect.left >= bounds)
			rect.left = 0;
		else
			rect.left += increment;
		sprite.setTextureRect(rect);
		clock.restart();
	}
	updatePosition(dt);
}

void SpriteAnimate::jump( ){

  	jumpSound.openFromFile("content/jump.ogg") ;
	jumpSound.play();
	if(sprite.getPosition().y == defaultPos)
		velocity = -25;
}

// void SpriteAnimate::slide(){
// 	velocity = 25;
// }

void SpriteAnimate::updatePosition(float dt){
	velocity += gravity*dt;
	y += velocity;
	if(y > defaultPos)
		y = defaultPos;
	if(y < 200)
		y = 200;
	if(y != defaultPos)
		frames = 0.15;
	else
		frames = 0.05;
	sprite.setPosition(x,y);
}