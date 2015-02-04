#include "render2d.h"

namespace View {

void Render2D::init()
{
}

void Render2D::update(const Model::GameState& newState)
{
    window->clear();

    boardPainter.setGameState(&newState);
    boardPainter.draw();

    window->display();        
}

void Render2D::shutdown()
{
}    

Model::Coord Render2D::setAndGetCoordByPosition(sf::Vector2f position)
{
    return boardPainter.setAndGetCursorByPosition(position);
}


Render2D::~Render2D()
{
}    

}