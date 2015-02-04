#ifndef LOCALGAMECONTROLLER_H
#define LOCALGAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "View/render2d.h"
#include "Controller/gamecontroller.h"

class LocalGameController : public GameController
{
    sf::RenderWindow* window;
    Model::Game game;
    View::Render2D renderer;
    Model::Coord cursor {-1, -1, -1};

    void initLocalGame();
    bool update(sf::Event event);
    void setCursor(sf::Event event);
    
public:
    LocalGameController(sf::RenderWindow* theWindow);
    ~LocalGameController();
    virtual void dispatchEvents();
};

#endif // LOCALGAMECONTROLLER_H
