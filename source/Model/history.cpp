#include "history.h"

#include "creation.h"

namespace Model 
{

History::History(Board* theBoard) : board(theBoard)
{
    eventLog.emplace_back(PointerToGameEvent {new Creation(board, this)});
    current = eventLog.begin();
    actualize();
}

void History::clearFuture()
{
    eventLog.erase(current, eventLog.end());
}

bool History::actualize()
{
    bool success = (current != eventLog.end());
    while (current != eventLog.end())
    {
	success &= stepForward();
    }
    return success;
}

bool History::stepForward()
{
    bool success = false;
    if (current != eventLog.end())
    {
	success = (*current)->execute();
	++current;
    }
    return success;
}

bool History::stepBack()
{
    bool success = false;
    if (current - 1 != eventLog.begin())
    {
	--current;
	success = (*current)->revert();
    }
    return success;
}


}