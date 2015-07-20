// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "render25d.h"

namespace View {

Render25D::Render25D(sf::RenderWindow* theWindow, 
	Model::IGameInfo* theGame, EventQueue* theEventQueue) 
	: game{theGame}, eventQueue {theEventQueue}, window(theWindow)
	, boardPainter(theWindow, &style, theGame, theEventQueue)
	, panelPainter(theWindow, &style)
{
    message = "";
    window->setVerticalSyncEnabled(true);
    panelPainter.setTopLeft(sf::Vector2f{20, 300});    
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