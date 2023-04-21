#include "../include/general.h"
#include "../include/game.h"
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

void Game::render(){
    window -> clear();
    window -> display();
}

void Game::update(){
    pollEvents();

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
            case Event::KeyPressed:
                if(sfmlEvent.key.code == Keyboard::Space){
                }
            break;
        }
    }
}
