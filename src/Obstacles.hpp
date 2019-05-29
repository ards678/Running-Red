#include "Main.hpp"
#include "Collision.hpp"

using namespace std;
using namespace sf;

class Obstacle{
public:
	Obstacle(String);
	Sprite sprite;
	Texture t;
	int top;
	int x = 1280;
	int width = 10;
	int speed = -7;
	bool isHit(Sprite);
	void update();
	Clock clock;
};

Obstacle::Obstacle(String s){
	// srand(time(NULL));
	// top = (rand() % 3);
	// String a[] = {"content/obstacle1.png", "content/obstacle2.png", "content/obstacle3.png"};
	t.loadFromFile(s);
	sprite.setTexture(t);
	// sprite.setFillColor(Color(255,0,0));
	sprite.setOrigin(50,sprite.getLocalBounds().height);
	sprite.setPosition(x,444);

}

bool Obstacle::isHit(Sprite s){
	return Collision::PixelPerfectTest(sprite, s);
}

void Obstacle::update(){
	x += speed;
	sprite.setPosition(x, 444);
}