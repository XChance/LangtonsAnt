#ifndef LANGTONS_ANT_ANT_H
#define LANGTONS_ANT_ANT_H

#include "SFML/Graphics.hpp"

enum Direction{
    Up,
    Down,
    Left,
    Right
};

class Ant {
public:
    Ant();

    void turn(int dir);

    sf::Vector2i getPos();
private:
    sf::Vector2i getLeft();
    sf::Vector2i getRight();


    sf::Vector2i pos;

    Direction dir;
};


#endif //LANGTONS_ANT_ANT_H
