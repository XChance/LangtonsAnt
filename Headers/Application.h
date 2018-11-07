#ifndef DOODLE_JUMP_APPLICATION_H
#define DOODLE_JUMP_APPLICATION_H

#include "SFML/Graphics.hpp"
#include "../Headers/Automaton.h"

class Application{
public:
    Application();

    void run();
private:
    void update();
    void render();
    void pollEvents();

    sf::RenderWindow renderWindow;

    sf::View windowView;

    sf::Font font;
    sf::Text stepsAmt;
    int steps;

    bool paused;
    Automaton automaton;
};


#endif //DOODLE_JUMP_APPLICATION_H
