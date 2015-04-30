#include "render2d.h"

namespace View {

Render2D::Render2D(sf::RenderWindow* theWindow) 
    : window(theWindow), boardPainter(theWindow, &style), panelPainter(theWindow, &style)
{
    window->setVerticalSyncEnabled(true);
}

    
void Render2D::init(Model::Game* theGame)
{
	game = theGame;
}

void Render2D::update()
{
	auto newState = game->getGameState();
    window->clear();

    boardPainter.setGameState(&newState);
    boardPainter.draw();

    panelPainter.setGameState(&newState);
    panelPainter.setCursorInfo(&cursor);
    panelPainter.draw(sf::Vector2f{20, 300});
    
    window->display();        
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