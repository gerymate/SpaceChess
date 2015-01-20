#ifndef BOARDPAINTER2D_H
#define BOARDPAINTER2D_H

#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "boardpainter.h"

class BoardPainter2D
{
    sf::RenderWindow* window;
    BoardPainter boardPainter;
public:
    BoardPainter2D(sf::RenderWindow* theWindow) : window(theWindow), boardPainter(theWindow) {};
    ~BoardPainter2D();
    void init();
    void update(GameState& newState);  
    void shutdown();  
};

#endif
