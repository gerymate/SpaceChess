// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "core.h"


Core::Core(Model::Game* theGame, EventQueue* theEventQueue, View::IRenderer* theRenderer)
    : game{theGame}, eventQueue{theEventQueue}, renderer{theRenderer}
{
}
