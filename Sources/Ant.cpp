#include "../Headers/Ant.h"

Ant::Ant() {
    pos = {80, 80};
    dir = Up;
}

void Ant::turn(int dir) {
    switch (dir){
        case 0:
            pos += getLeft();
            break;
        case 1:
            pos += getRight();
            break;
        default:
            break;
    }
}

sf::Vector2i Ant::getLeft() {
    sf::Vector2i left;
    switch (dir){
        case Up:
            left = sf::Vector2i(-1, 0);
            dir = Left;
            break;
        case Down:
            left = sf::Vector2i(1, 0);
            dir = Right;
            break;
        case Left:
            left = sf::Vector2i(0, 1);
            dir = Down;
            break;
        case Right:
            left = sf::Vector2i(0, -1);
            dir = Up;
            break;
    }

    return left;
}

sf::Vector2i Ant::getRight() {
    sf::Vector2i right;
    switch (dir){
        case Up:
            right = sf::Vector2i(1, 0);
            dir = Right;
            break;
        case Down:
            right = sf::Vector2i(-1, 0);
            dir = Left;
            break;
        case Left:
            right = sf::Vector2i(0, -1);
            dir = Up;
            break;
        case Right:
            right = sf::Vector2i(0, 1);
            dir = Down;
            break;
    }

    return right;
}


//getters & setters

sf::Vector2i Ant::getPos() {
    return pos;
}