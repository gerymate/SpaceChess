// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef RENDER2D_H
#define RENDER2D_H

#include "common.h"
#include <SFML/Graphics.hpp>
#include "Model/igameinfo.h"
#include "boardpainter.h"
#include "panelpainter.h"

namespace View {

class Render2D
{
    Model::IGameInfo* game;
    EventQueue* eventQueue;
    sf::RenderWindow* window;
    StyleSheet style;
    BoardPainter boardPainter;
    PanelPainter panelPainter;
    Model::Position cursor;
    std::string message;
public:
    Render2D(sf::RenderWindow* theWindow, Model::IGameInfo* theGame, 
	     EventQueue* theEventQueue);
    ~Render2D();
    void update();
    void setLocalPlayers(Model::Player theLocalPlayers);
    void handleClick(sf::Vector2f &mousePosition);
    Model::Position setAndGetBoardCursorFromScreenPosition(sf::Vector2f position);
    void setSelectedField(Model::Position theSelectedField) 
	    { boardPainter.setSelectedField(theSelectedField); }
    void clearSelectedField() { boardPainter.clearSelectedField(); }
    void setHighlightedFields(Model::PointerToPositionList thePositions)
	    { boardPainter.setHighlightedFields(thePositions); }
    void clearHighlightedFields() { setHighlightedFields(nullptr); }
    void setMessage(const std::string& theMessage);
};

}

#endif
