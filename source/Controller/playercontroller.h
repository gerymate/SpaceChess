#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "common.h"
#include "event.h"
#include "Model/game.h"
#include "Model/position.h"
#include "View/render2d.h"

namespace Controller
{

class PlayerController
{
    Model::Game* game;
    View::Render2D* renderer;
    EventQueue* eventQueue;
    Model::Position firstSelection {Model::Position::Invalid};
    
    void handleFirstSelection(Model::Position theClickPosition);
    void handleSecondSelection(Model::Position theClickPosition);
public:
    PlayerController(Model::Game* theGame, View::Render2D* theRenderer, EventQueue* theEventQueue);
    void handleSelection(PointerToEvent event);
};

}
#endif // PLAYERCONTROLLER_H
