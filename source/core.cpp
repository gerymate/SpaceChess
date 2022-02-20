// (C) Máté Gergely - gerymate@gmail.com
#include "core.h"


Core::Core(Model::Game* theGame, EventQueue* theEventQueue, View::IRenderer* theRenderer)
    : game{theGame}, eventQueue{theEventQueue}, renderer{theRenderer}
{
}
