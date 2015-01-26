#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Model/gamestate.h"

class GameController
{
protected:
    Model::GameState loadBoardFromFile();
public:
    virtual ~GameController() {};
    virtual void dispatchEvents() = 0;    
};

#endif // GAMECONTROLLER_H
