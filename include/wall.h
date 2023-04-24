#ifndef WALL_H_
#define WALL_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include "general.h"
#include <vector>

#define WALL_VELOCITY 10
#define LB_PERCENTAGE 40
#define UB_PERCENTAGE 60
#define GAP 450
#define WALL_WIDTH 50
#define WALL_SZ 3

using namespace std;
using namespace sf;

const Color WALL_COLOR(33, 255, 200, 255);

int genRandomHeight();

class Wall{
    private:
        int height;
        RectangleShape topWall;
        RectangleShape bottomWall;
        int velocity;
    public:
        Wall();
        virtual ~Wall();
        void reSpawn();
        void move(int x);
        float getX();
        float getY();
        RectangleShape getTop();
        RectangleShape getBottom();
        void draw(RenderTarget *target);
};

class Walls{
    private:
        vector<Wall*> list;
        Texture wallEdge;
        Texture wallPillar;
    public:
        Walls(int sz);
        Walls();
        bool isTouching(Sprite sprite);
        virtual ~Walls();
        void incrementMovement();
        void draw(RenderTarget *target);
};
#endif // WALL_H_
