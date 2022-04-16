// (C) Máté Gergely - gerymate@gmail.com
#ifndef CORE_H
#define CORE_H

#include <SFML/Window.hpp>
#include "common.h"
#include "Model/game.h"
#include "irenderer.h"
#include "event.h"

class Core
{
private:
    Model::Game* game;
    EventQueue* eventQueue;
    View::IRenderer* renderer;
public:
    Core(Model::Game* theGame, EventQueue* theEventQueue, View::IRenderer* theRenderer);
    Model::Game* getGame() const { return game; }
    EventQueue* getEventQueue() const { return eventQueue; }
    View::IRenderer* getRenderer() const { return renderer; }
};


#endif 