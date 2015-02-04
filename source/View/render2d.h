#ifndef RENDER2D_H
#define RENDER2D_H

#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "boardpainter.h"

namespace View {

class Render2D
{
    sf::RenderWindow* window;
    BoardPainter boardPainter;
public:
    Render2D(sf::RenderWindow* theWindow) : window(theWindow), boardPainter(theWindow) {};
    ~Render2D();
    void init();
    void update(const Model::GameState& newState);  
    void shutdown();  
    Model::Coord setAndGetCoordByPosition(sf::Vector2f position);
};

}

#endif
