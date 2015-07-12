// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "render2d.h"

namespace View {

Render2D::Render2D(sf::RenderWindow* theWindow, 
	Model::IGameInfo* theGame, EventQueue* theEventQueue) 
	: game{theGame}, eventQueue {theEventQueue}, window(theWindow)
	, boardPainter(theWindow, &style, theGame, theEventQueue)
	, panelPainter(theWindow, &style)
{
    message = "";
    window->setVerticalSyncEnabled(true);
    panelPainter.setTopLeft(sf::Vector2f{20, 300});    
}

void Render2D::update()
{
    auto newState = game->getGameState();
    window->clear();

    setAndGetBoardCursorFromScreenPosition(sf::Vector2f{ sf::Mouse::getPosition(*window) });
    
    boardPainter.setGameState(&newState);
    boardPainter.draw();

    panelPainter.setGameState(&newState);
    panelPainter.setCursorInfo(&cursor);
    panelPainter.draw();
    
    window->display();        
}

void Render2D::setLocalPlayers(Model::Player theLocalPlayers)
{
    boardPainter.setLocalPlayers(theLocalPlayers);
    panelPainter.setLocalPlayer(theLocalPlayers);
}

void Render2D::setMessage(const std::string& theMessage)
{
    panelPainter.setMessage(theMessage);
}

void Render2D::handleClick(sf::Vector2f& mousePosition)
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

Model::Position Render2D::setAndGetBoardCursorFromScreenPosition(sf::Vector2f position)
{
    return cursor = boardPainter.setAndGetBoardCursorFromScreenPosition(position);
}

Render2D::~Render2D()
{
}    

}