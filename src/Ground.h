#include "Main.hpp"
// #include "Collision.hpp"

using namespace std;
using namespace sf;


 class Ground{
     public:
     Texture texture;
     Sprite sprite;
    Vector2f pos;
    int num = 0;
    float xVel = 0;
    Ground(string path, Vector2f pos, int num ){
        texture.loadFromFile(path);
        this->pos =pos;
        this->num = num;
        // move();

    };

    void move(){
        xVel = -11;

    };
    void stop(){

        xVel = 0;
    };
    Sprite drawGround(int speed, float dt){
        sprite.setTexture(texture);
        sprite.setPosition(pos);
        xVel = speed;
        pos.x+= xVel*dt;

        // cout<<"otoy"<<speed<<endl;
        if(pos.x<= -1280*2) teleport();

        return sprite;
    };

    void teleport(){
        pos.x= 1280*2;
    };

 };