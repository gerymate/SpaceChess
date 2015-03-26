#include "history.h"

#include "creation.h"

namespace Model 
{

History::History(Board* theBoard) : board(theBoard)
{
    eventLog.emplace_back(PointerToGameEvent {new Creation(board, this)});
    actualize();
}

void History::clearFuture()
{
    eventLog.resize(indexOfNextEvent);
}

bool History::actualize()
{
    bool success = (indexOfNextEvent != eventLog.size());
    while (indexOfNextEvent != eventLog.size())
    {
	success &= stepForward();
    }
    return success;
}

bool History::stepForward()
{
    bool success = false;
    if (indexOfNextEvent != eventLog.size())
    {
	success = eventLog.at(indexOfNextEvent)->execute();
	++indexOfNextEvent;
    }
    return success;
}

bool History::stepBack()
{
    bool success = false;
    if (indexOfNextEvent - 1 != 0)
    {
	--indexOfNextEvent;
	success = eventLog.at(indexOfNextEvent)->revert();
    }
    return success;
}

std::ostream& operator<<(std::ostream& outputStream, const Model::History& history)
{
    outputStream << history.board;
    return outputStream;
    
}


std::istream& operator>>(std::istream& inputStream, Model::History& history)
{
    inputStream >> *(history.board);
    return inputStream;
    
    
}



}