#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

class View
{
    sf::RenderWindow window;
public:
    View();
    ~View();
    void init();
    void update();  
    void shutdown();  
};

#endif
