#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
using namespace std;
using namespace sf;

class Game {
    private:
        RenderWindow *window;
        VideoMode videoMode;
        Event sfmlEvent;
        void initVariables();
        void initWindow();
        void close();
        void pollEvents();
    public:
        Game();
        virtual ~Game();
        bool isRunning();
        void update();
        void render();
};


#endif // GAME_H_
