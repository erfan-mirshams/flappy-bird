#include "../include/general.h"
#include "../include/game.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

void Game::initVariables(){
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
    window -> display();
}

void Game::update(){
    pollEvents();
    bird.incrementMovement();
    if(hasTimePassed()){
        bird.incrementImage();
    }
}

Game::~Game(){
    delete window;
}

void Game::close(){
    window -> close();
}

void Game::pollEvents(){
    while(window -> pollEvent(sfmlEvent)){
        switch(sfmlEvent.type){
            case Event::Closed:
                close();
            break;
            case Event::KeyReleased:
                if(sfmlEvent.key.code == Keyboard::Space){
                    bird.jump();
                }
            break;
        }
    }
}
