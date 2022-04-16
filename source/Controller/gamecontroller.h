// (C) Máté Gergely - gerymate@gmail.com
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Window.hpp>
#include "common.h"
#include "core.h"
#include "Model/game.h"
#include "irenderer.h"
#include "event.h"

namespace Controller
{
    
class GameController
{
protected:
    std::shared_ptr<Core> core;

    virtual void handleSystemEvents() = 0;
    virtual void handleGameEvents() = 0;    
public:
    GameController(std::shared_ptr<Core> theCore);
    virtual ~GameController();
    virtual void mainLoop();
    std::shared_ptr<Core> getCore() const { return core; }
};

}
#endif // GAMECONTROLLER_H
