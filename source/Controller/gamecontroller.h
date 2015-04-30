#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "common.h"
#include <SFML/Graphics.hpp>
#include "Model/game.h"
#include "Model/gamestate.h"
#include "View/render2d.h"
#include "Controller/event.h"

namespace Controller
{
    
class GameController
{
    sf::RenderWindow* window;
    Model::Game game;
    EventQueue eventQueue;
    View::Render2D renderer;

    Model::Coord cursor {-1, -1, -1};

    void initLocalGame();
    void setCursor(sf::Event event);
    Model::GameState loadBoardFromFile();
    void handleSystemEvents();
    void handleGameEvents();
    
public:
    GameController(sf::RenderWindow* theWindow);
    virtual ~GameController();
    void mainLoop();
};

}
#endif // GAMECONTROLLER_H
