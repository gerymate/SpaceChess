#ifndef RENDER2D_H
#define RENDER2D_H

#include <SFML/Graphics.hpp>
#include "Model/gamestate.h"
#include "Model/coord.h"
#include "boardpainter.h"
#include "panelpainter.h"

namespace View {

class Render2D
{
    sf::RenderWindow* window;
    StyleSheet style;
    BoardPainter boardPainter;
    PanelPainter panelPainter;
    Model::Coord cursor;
public:
    Render2D(sf::RenderWindow* theWindow);
    ~Render2D();
    void init();
    void update(const Model::GameState& newState);  
    void shutdown();  
    Model::Coord setAndGetCoordByPosition(sf::Vector2f position);
};

}

#endif
