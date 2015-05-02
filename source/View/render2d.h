#ifndef RENDER2D_H
#define RENDER2D_H

#include "common.h"
#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "Model/position.h"
#include "boardpainter.h"
#include "panelpainter.h"

namespace View {

class Render2D
{
    Model::Game* game;
    EventQueue* eventQueue;
    sf::RenderWindow* window;
    StyleSheet style;
    BoardPainter boardPainter;
    PanelPainter panelPainter;
    Model::Position cursor;
public:
    Render2D(sf::RenderWindow* theWindow, Model::Game* theGame, EventQueue* theEventQueue);
    ~Render2D();
    void update();  
    void shutdown();
    void handleClick(sf::Vector2f &mousePosition);
    Model::Position setAndGetBoardCursorFromScreenPosition(sf::Vector2f position);
    void setSelectedField(Model::Position theSelectedField) 
	    { boardPainter.setSelectedField(theSelectedField); }
    void clearSelectedField() { boardPainter.clearSelectedField(); }
    void setHighlightedFields(Model::PointerToPositionList thePositions)
	    { boardPainter.setHighlightedFields(thePositions); }
    void clearHighlightedFields() { setHighlightedFields(nullptr); }

};

}

#endif
