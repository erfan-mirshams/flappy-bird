#include "../include/general.h"
#include "../include/game.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <type_traits>

void Game::initVariables(){
    walls = new Walls(WALL_SZ);
    endGame = false;
}

void Game::initWindow(){
    videoMode = VideoMode(WIDTH, HEIGHT);
    window = new RenderWindow(videoMode, GAME_TITLE, Style::None);
    window -> setFramerateLimit(FRAME_RATE_LIMIT);
}

bool Game::isRunning(){
    return window -> isOpen();
}

Game::Game(){
    initVariables();
    initWindow();
}

bool Game::hasTimePassed(){
    if(clock.getElapsedTime().asMilliseconds() >= ELAPSED_TIME_LIMIT){
        clock.restart();
        return true;
    }
    return false;
}

void Game::draw(RenderTarget *target, Sprite sprite){
    target -> draw(sprite);
}

void Game::render(){
    window -> clear();
    draw(window, bird.getSprite());
    walls -> draw(window);
    window -> display();
}

void Game::update(){
    pollEvents();
    bird.incrementMovement();
    walls -> incrementMovement();
    if(walls -> isTouching(bird.getSprite()) || bird.isLow()){
        endGame = true;
    }
    if(hasTimePassed()){
        bird.incrementImage();
    }
    if(endGame){
        close();
    }
}

Game::~Game(){
    delete window;
    delete walls;
}

void Game::close(){
    window -> close();
}

void Game::pollEvents(){
    while(window -> pollEvent(sfmlEvent)){
        switch(sfmlEvent.type){
            case Event::Closed:
                endGame = true;
            break;
            case Event::KeyReleased:
                if(sfmlEvent.key.code == Keyboard::Space){
                    bird.jump();
                }
            break;
        }
    }
}
