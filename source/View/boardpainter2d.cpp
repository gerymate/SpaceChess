#include "boardpainter2d.h"

void BoardPainter2D::init()
{
}

void BoardPainter2D::update(GameState& newState)
{
    window->clear();

    boardPainter.setBoard(&(newState.board));
    boardPainter.draw();

    window->display();        
}    

void BoardPainter2D::shutdown()
{
}    


BoardPainter2D::~BoardPainter2D()
{
}    
