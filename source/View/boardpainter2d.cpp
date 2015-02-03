#include "boardpainter2d.h"

namespace View {

void BoardPainter2D::init()
{
}

void BoardPainter2D::update(Model::GameState& newState)
{
    window->clear();

    boardPainter.setBoard(&(newState.board));
    boardPainter.draw();

    window->display();        
}

void BoardPainter2D::shutdown()
{
}    

Model::Coord BoardPainter2D::getCoordByPosition(sf::Vector2f position)
{
    return boardPainter.getCoordByPosition(position);
}


BoardPainter2D::~BoardPainter2D()
{
}    

}