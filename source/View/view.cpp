#include "view.h"

View::View()
{
}

void View::init()
{
    window.create( sf::VideoMode { 640, 480 }, "SpaceChess" );
}

void View::update()
{
    sf::CircleShape shape { 100.f };
    shape.setFillColor(sf::Color::Yellow);

    window.clear();
    window.draw(shape);
    window.display();        
}    

void View::shutdown()
{
    window.close();        
}    


View::~View()
{
}    
