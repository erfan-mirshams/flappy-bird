#include "../include/general.h"
#include "../include/bird.h"
#include <SFML/Graphics/Sprite.hpp>

void Bird::initTextures(){
    for(int i = 0; i < BIRD_IMG_SZ; i++){
        textures[i].loadFromFile(IMG_DIR + fileNames[i]);
    }
}

Bird::Bird(){
    initTextures();
    imageIndex = 0;
    sprite.setTexture(textures[imageIndex]);
    sprite.setScale(IMG_SCALE, IMG_SCALE);
    sprite.setOrigin(percentage(HALF, textures[imageIndex].getSize().x), percentage(HALF, textures[imageIndex].getSize().y));
    velocity = INITIAL_VELOCITY;
    acceleration = INITIAL_ACCELERATION;
    angular_velocity = INITIAL_ANGULAR_VELOCITY;
    sprite.setPosition(percentage(WIDTH_PERCENTAGE, WIDTH), percentage(HEIGHT_PERCENTAGE, HEIGHT));
}

void Bird::jump(){
    velocity = -5 * INITIAL_VELOCITY;
    angular_velocity = -INITIAL_ANGULAR_VELOCITY;
}

Bird::~Bird(){

}

void Bird::incrementMovement(){
    sprite.move(0, velocity);
    velocity += acceleration;
    sprite.rotate(angular_velocity);
    float rot = convertRotation(sprite.getRotation());
    if(velocity < 0){
        angular_velocity = -INITIAL_ANGULAR_VELOCITY * 2;
    }
    if(rot <= HIGH_ANGLE){
        angular_velocity = 0;
    }
    if(velocity > 0){
        angular_velocity = INITIAL_ANGULAR_VELOCITY;
    }
    if(rot >= RIGHT_ANGLE){
        angular_velocity = 0;
    }
}

void Bird::incrementImage(){
    imageIndex++;
    imageIndex %= BIRD_IMG_SZ;
    sprite.setTexture(textures[imageIndex]);
}

Sprite Bird::getSprite(){
    return sprite;
}
