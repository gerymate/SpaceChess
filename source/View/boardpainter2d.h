#ifndef BOARDPAINTER2D_H
#define BOARDPAINTER2D_H

#include <SFML/Graphics.hpp>

class BoardPainter2D
{
    sf::RenderWindow window;
public:
    BoardPainter2D();
    ~BoardPainter2D();
    void init();
    void update();  
    void shutdown();  
};

#endif
