#include "render2d.h"

namespace View {

Render2D::Render2D(sf::RenderWindow* theWindow, 
	Model::Game* theGame, Controller::EventQueue* theEventQueue) 
	: game{theGame}, eventQueue {theEventQueue}, window(theWindow), boardPainter(theWindow, &style, theGame, theEventQueue), panelPainter(theWindow, &style)
{
    window->setVerticalSyncEnabled(true);
    panelPainter.setTopLeft(sf::Vector2f{20, 300});    
}

void Render2D::update()
{
    auto newState = game->getGameState();
    window->clear();

    setAndGetCoordByPosition(sf::Vector2f{ sf::Mouse::getPosition(*window) });
    
    boardPainter.setGameState(&newState);
    boardPainter.draw();

    panelPainter.setGameState(&newState);
    panelPainter.setCursorInfo(&cursor);
    panelPainter.draw();
    
    window->display();        
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

void Render2D::shutdown()
{
}    

Model::Coord Render2D::setAndGetCoordByPosition(sf::Vector2f position)
{
    return cursor = boardPainter.setAndGetCursorByPosition(position);
}


Render2D::~Render2D()
{
}    

}