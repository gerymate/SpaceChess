// (C) Máté Gergely - gerymate@gmail.com
#include "gamecontroller.h"

namespace Controller
{

GameController::GameController(std::shared_ptr<Core> theCore)
    : core{ theCore }
{
}

GameController::~GameController()
{
}

void GameController::mainLoop() // is this used anywhere?
{
    
    while (core->getRenderer()->getWindow()->isOpen())
    {    
	handleSystemEvents();
	handleGameEvents();
	core->getRenderer()->update();
    }
}


}