#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "common.h"
#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "View/render2d.h"
#include "event.h"
#include "Controller/playercontroller.h"
#include "Model/position.h"

namespace Controller
{
    
class GameController
{
protected:
    sf::RenderWindow* window;
    Model::Game game;
    EventQueue eventQueue;
    View::Render2D renderer;

    virtual void handleSystemEvents() = 0;
    virtual void handleGameEvents() = 0;    
public:
    GameController(sf::RenderWindow* theWindow);
    virtual ~GameController();
    virtual void mainLoop();
};

}
#endif // GAMECONTROLLER_H
