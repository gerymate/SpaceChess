#include "gamecontroller.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Controller
{

GameController::GameController(sf::RenderWindow* theWindow) 
    : window{theWindow}, renderer{theWindow, &game, &eventQueue}
{
}

GameController::~GameController()
{
}

void GameController::mainLoop() // is this used anywhere?
{
    while (window->isOpen())
    {    
	handleSystemEvents();
	handleGameEvents();
	renderer.update();
    }
}


}