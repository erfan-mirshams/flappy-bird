#ifndef GAME_H_
#define GAME_H_

#include "general.h"
#include "bird.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#define ELAPSED_TIME_LIMIT 150

using namespace sf;
using namespace std;

class Game{
    private:
        bool endGame;
        RenderWindow *window;
        Clock clock;
        VideoMode videoMode;
        Event sfmlEvent;
        Bird bird;
        Walls *walls;
        void initVariables();
        void initWindow();
        void close();
        void pollEvents();
        void draw(RenderTarget *target, Sprite sprite);
        bool hasTimePassed();
    public:
        Game();
        virtual ~Game();
        bool isRunning();
        void update();
        void render();
};


#endif // GAME_H_
