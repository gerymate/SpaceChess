// (C) Máté Gergely - gerymate@gmail.com
#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "common.h"
#include "event.h"
#include "core.h"
#include "Model/game.h"
#include "Model/position.h"
#include "irenderer.h"

namespace Controller
{

class PlayerController
{
    std::shared_ptr<Core> core;
    Model::Position firstSelection {Model::Position::Invalid};
    
    void handleFirstSelection(Model::Position theClickPosition);
    void handleSecondSelection(Model::Position theClickPosition);
public:
    PlayerController(std::shared_ptr<Core> theCore);
    void handleSelection(PointerToEvent event);
};

}
#endif // PLAYERCONTROLLER_H
