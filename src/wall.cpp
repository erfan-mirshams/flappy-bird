#include "../include/wall.h"

int genRandomHeight(){
    return randomIntBetween(percentage(LB_PERCENTAGE, HEIGHT), percentage(UB_PERCENTAGE, HEIGHT));
}

void Wall::move(int x){
    topWall.move(x, 0);
    bottomWall.move(x, 0);
}

RectangleShape Wall::getTop(){
    return topWall;
}

RectangleShape Wall::getBottom(){
    return bottomWall;
}

float Wall::getX(){
    return topWall.getPosition().x;
}

float Wall::getY(){
    return bottomWall.getPosition().y - GAP;
}

Walls::Walls(int sz){
    for(int i = 0; i < sz; i++){
        list.push_back(new Wall());
        list[i] -> move(i * HEIGHT / sz);
    }
}

void Wall::draw(RenderTarget *target){
    target -> draw(topWall);
    target -> draw(bottomWall);
}

void Walls::draw(RenderTarget *target){
    for(int i = 0; i < (int)list.size(); i++){
        list[i] -> draw(target);
    }
}

void Walls::incrementMovement(){
    for(int i = 0; i < (int)list.size(); i++){
        list[i] -> move(-WALL_VELOCITY);
        if(list[i] -> getX() <= -WALL_WIDTH){
            list[i] -> reSpawn();
        }
    }
}

bool Walls::isTouching(Sprite sprite){
    for(int i = 0; i < (int)list.size(); i++){
        if(sprite.getGlobalBounds().intersects(list[i] -> getTop().getGlobalBounds()) || sprite.getGlobalBounds().intersects(list[i] -> getBottom().getGlobalBounds())){
            return true;
        }
    }
    return false;
}

Walls::Walls(){
    Walls(WALL_SZ);
}

Walls::~Walls(){
    for(auto &w : list){
        delete w;
    }
}

void Wall::reSpawn(){
    int h = genRandomHeight();
    topWall.setSize(Vector2f(WALL_WIDTH, h));
    bottomWall.setSize(Vector2f(WALL_WIDTH, HEIGHT - h - GAP));
    topWall.setPosition(Vector2f(WIDTH, 0));
    bottomWall.setPosition(Vector2f(WIDTH, h + GAP));
}

Wall::Wall(){
    reSpawn();
    topWall.setFillColor(WALL_COLOR);
    bottomWall.setFillColor(WALL_COLOR);
}

Wall::~Wall(){

}
