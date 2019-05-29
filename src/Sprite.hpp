#include "Main.hpp"

using namespace std;
using namespace sf;

class SpriteAnimate{
public:
	SpriteAnimate(String ,IntRect, Vector2f, float, int, int);
	void animate();
	void jump();
	//void slide();
	Sprite sprite;
	int increment;
	float x, y;
private:
	void updatePosition();
	Texture t;
	IntRect rect;
	Clock clock, c;
	float defaultPos;
	float velocity = 0, gravity = 1;
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

void SpriteAnimate::animate(){
	if (clock.getElapsedTime().asSeconds() > frames){
		if (rect.left >= bounds)
			rect.left = 0;
		else
			rect.left += increment;
		sprite.setTextureRect(rect);
		clock.restart();
	}
	updatePosition();
}

void SpriteAnimate::jump(){
	if(sprite.getPosition().y == defaultPos)
		velocity = -25;
}

// void SpriteAnimate::slide(){
// 	velocity = 25;
// }

void SpriteAnimate::updatePosition(){
	velocity += gravity;
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