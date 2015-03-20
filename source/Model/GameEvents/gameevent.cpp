#include "gameevent.h"

namespace Model
{

void GameEvent::setHistory(History* theHistory)
{
    history = theHistory;
}

    
GameEvent::~GameEvent()
{

}

Board* GameEvent::board = nullptr;
History* GameEvent::history = nullptr;

}