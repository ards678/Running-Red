#include "Main.hpp"
#include "Collision.hpp"
#include <cmath>
#include<string>
#include <cstring>
using namespace std;
using namespace sf;

class Obstacle{
public:
	Obstacle(String, int );
	Sprite sprite;
	Texture t;
	int top;
	int type;
	int x = 1280;
	int width = 10;
	float speed = -7;
	bool isHit(Sprite);
	void update(float dt);
	Clock clock;
};

Obstacle::Obstacle(String s, int type){
	srand(time(NULL)+speed+width);
	int rands = 100*rand()%6;
	this->type = type;
	x = 1280+ (pow(-1,rands )*rands);
	cout<<"rands"<<rands<<endl;

	// srand(time(NULL));
	// top = (rand() % 3);
	// String a[] = {"content/obstacle1.png", "content/obstacle2.png", "content/obstacle3.png"};
	t.loadFromFile(s);
	sprite.setTexture(t);
	sprite.setOrigin(50,sprite.getLocalBounds().height);
	sprite.setPosition(x,(this->type == 2)?330:444);

}

bool Obstacle::isHit(Sprite s){
	return Collision::PixelPerfectTest(sprite, s);
}

void Obstacle::update(float dt){
	x += speed*dt;
	sprite.setPosition(x,(this->type == 2)?330:444);
}