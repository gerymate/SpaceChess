// (C) Máté Gergely - gerymate@gmail.com
#include "render25d.h"
#include <algorithm>

namespace View {

Render25D::Render25D(sf::RenderWindow* theWindow, 
	Model::IGameInfo* theGame, EventQueue* theEventQueue) 
	: window{theWindow}, game{theGame}, eventQueue {theEventQueue}
	, style{&textureManager, &fontManager}
	, boardPainter(theWindow, &style, theGame, theEventQueue)
	, panelPainter(theWindow, &style)
{
    int windowBoxSize = std::min(window->getSize().x, window->getSize().y);
    style.setBoardSize(windowBoxSize * boardToWindowRatio);
    message = "";
    window->setVerticalSyncEnabled(true);
    panelPainter.setTopLeft(sf::Vector2f{style.getMarginSize(), style.getMarginSize() + boardPainter.getRect().height});    
}

void Render25D::update()
{
    auto newState = game->getGameState();
    window->clear();

    setAndGetBoardCursorFromScreenPosition(sf::Vector2f{ sf::Mouse::getPosition(*window) });
    
    boardPainter.setGameState(&newState);
    boardPainter.update();
    boardPainter.draw();

    panelPainter.setGameState(&newState);
    panelPainter.setCursorInfo(&cursor);
    panelPainter.draw();
    
    window->display();        
}

void Render25D::setLocalPlayers(Model::Player theLocalPlayers)
{
    boardPainter.setLocalPlayers(theLocalPlayers);
    panelPainter.setLocalPlayer(theLocalPlayers);
}

void Render25D::setMessage(const std::string& theMessage)
{
    panelPainter.setMessage(theMessage);
}

void Render25D::handleClick(sf::Vector2f& mousePosition)
{
    if (boardPainter.getRect().contains(mousePosition))
    {
	boardPainter.handleClick(mousePosition);
    } 
    else if (panelPainter.getRect().contains(mousePosition))
    {
	panelPainter.handleClick(mousePosition);
    }
}

void Render25D::zoomIn()
{
    boardPainter.zoomIn();
}

void Render25D::zoomOut()
{
    boardPainter.zoomOut();
}

Model::Position Render25D::setAndGetBoardCursorFromScreenPosition(sf::Vector2f position)
{
    return cursor = boardPainter.setAndGetBoardCursorFromScreenPosition(position);
}

void Render25D::setSelectedField(Model::Position theSelectedField)
{ 
    boardPainter.setSelectedField(theSelectedField); 
}

void Render25D::clearSelectedField()
{ 
    boardPainter.clearSelectedField(); 
}

void Render25D::setHighlightedFields(Model::PointerToPositionList thePositions)
{ 
    boardPainter.setHighlightedFields(thePositions); 
}

void Render25D::clearHighlightedFields()
{ 
    setHighlightedFields(nullptr); 
}

sf::Window* Render25D::getWindow()
{ 
    return window; 
}

Render25D::~Render25D()
{
}    

}