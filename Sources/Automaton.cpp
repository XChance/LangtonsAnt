#include "../Headers/Automaton.h"

Automaton::Automaton() : cells(WIDTH * HEIGHT) {
    cellForEach([&](int x, int y){
        addQuad(x, y);
        cells[getCellIndex(x, y)] = Off;
    });

    cellForEach([&](int x, int y){
        setCellColor(getCellIndex(x, y));
    });
}

//Update method
void Automaton::update() {
    int index = getCellIndex(ant.getPos().x, ant.getPos().y);
    Cell& temp = cells[index];

    if(temp == On){
        temp = Off;
        ant.turn(1);
    }else{
        ant.turn(0);
        temp = On;
    }

    setCellColor(index);
}

void Automaton::render(sf::RenderWindow &renderWindow) {
    renderWindow.draw(cellVertices.data(), cellVertices.size(), sf::Quads);
}

void Automaton::setCellColor(int xIndex, int yIndex, sf::Color color) {
    int index = getCellIndex(xIndex, yIndex) * 4;
    for (int i = 0; i < 4; i++) {
        cellVertices[index + i].color = color;
    }
}

void Automaton::setCellColor(int index) {
    sf::Color color;

    if(cells[index] == On) {
        color = sf::Color::White;
    }else {
        color = sf::Color::Black;
    }

    int vertIndex = index * 4;
    for (int i = 0; i < 4; i++) {
        cellVertices[vertIndex + i].color = color;
    }
}

//Adds a Quad to the cellVertices vector. Quads are made up of
//4 Vertices which just have a position and color.
void Automaton::addQuad(int xIndex, int yIndex) {
    sf::Vertex topLeft;
    sf::Vertex topRight;
    sf::Vertex bottomLeft;
    sf::Vertex bottomRight;

    float pixelX = xIndex * CELL_SIZE;
    float pixelY = yIndex * CELL_SIZE;

    topLeft.position = { pixelX, pixelY };
    topRight.position = { pixelX + CELL_SIZE, pixelY };
    bottomLeft.position = { pixelX, pixelY + CELL_SIZE };
    bottomRight.position = { pixelX + CELL_SIZE, pixelY + CELL_SIZE };

    cellVertices.push_back(topLeft);
    cellVertices.push_back(bottomLeft);
    cellVertices.push_back(bottomRight);
    cellVertices.push_back(topRight);
}