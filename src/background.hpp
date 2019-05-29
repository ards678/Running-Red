#include "Main.hpp"

using namespace std;
using namespace sf;

class Background{
public:
	Background(String);
	Sprite sprite;
private:
	Texture t;
	int x, y, velocity;
	Clock clock;
};

Background::Background(String s){
	t.loadFromFile(s);
	sprite.setTexture(t);
}