#include "boardpainter2d.h"

BoardPainter2D::BoardPainter2D()
{
}

void BoardPainter2D::init()
{
    window.create( sf::VideoMode { 640, 480 }, "SpaceChess" );
}

void BoardPainter2D::update()
{
    sf::CircleShape shape { 100.f };
    shape.setFillColor(sf::Color::Yellow);

    window.clear();
    window.draw(shape);
    window.display();        
}    

void BoardPainter2D::shutdown()
{
    window.close();        
}    


BoardPainter2D::~BoardPainter2D()
{
}    
