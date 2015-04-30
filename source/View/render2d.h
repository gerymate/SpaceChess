#ifndef RENDER2D_H
#define RENDER2D_H

#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "Model/coord.h"
#include "boardpainter.h"
#include "panelpainter.h"

namespace View {

class Render2D
{
	Model::Game* game;
    sf::RenderWindow* window;
    StyleSheet style;
    BoardPainter boardPainter;
    PanelPainter panelPainter;
    Model::Coord cursor;
public:
    Render2D(sf::RenderWindow* theWindow);
    ~Render2D();
    void init(Model::Game* theGame);
    void update();  
    void shutdown();  
    Model::Coord setAndGetCoordByPosition(sf::Vector2f position);
};

}

#endif
