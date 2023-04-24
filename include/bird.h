#ifndef BIRD_H_
#define BIRD_H_

#include <SFML/Graphics/Sprite.hpp>
#define BIRD_IMG_SZ 4
#define IMG_SCALE 3.0
#define INITIAL_VELOCITY 5
#define INITIAL_ACCELERATION 1
#define INITIAL_ANGULAR_VELOCITY 3
#define RIGHT_ANGLE 90
#define HIGH_ANGLE -30
#define WIDTH_PERCENTAGE 20
#define HEIGHT_PERCENTAGE 50
#define IMG_DIR "../sprites/"
#include <SFML/Graphics.hpp>
#include "general.h"

using namespace sf;
using namespace std;

const string fileNames[BIRD_IMG_SZ] = {"yellowbird-downflap.png", "yellowbird-midflap.png", "yellowbird-upflap.png", "yellowbird-midflap.png"};

class Bird {
    private:
        Texture textures[BIRD_IMG_SZ];
        Sprite sprite;
        int imageIndex;
        int velocity;
        int angular_velocity;
        int acceleration;
        int angle;
        void initTextures();
    public:
        Sprite getSprite();
        Bird();
        virtual ~Bird();
        void incrementMovement();
        void incrementImage();
        void jump();
        bool isLow();
};

#endif // BIRD_H_
