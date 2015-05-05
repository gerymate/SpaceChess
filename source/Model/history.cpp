#include "history.h"

#include "creation.h"

namespace Model 
{

History::History(Game* theGame) : game{theGame}, board{theGame->getBoard()}
{
    eventLog.emplace_back(PointerToGameEvent {new Creation(game)});
    actualize();
}

void History::addEvent(PointerToGameEvent& event) 
{ 
    eventLog.push_back(event); 
}

PointerToGameEvent History::getCurrentEvent() const 
{ 
    return eventLog.at(indexOfNextEvent - 1); 
}

void History::reset() 
{ 
    indexOfNextEvent = 1; 
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

Player History::getPlayerForLastEvent() const 
{ 
    return getCurrentEvent()->getPlayer(); 
}

int History::getMoveNumberForLastEvent() const
{
    return getCurrentEvent()->getMoveNumber();
}

Player History::getNextPlayer() const
{
    Player lastPlayer = getCurrentEvent()->getPlayer();
    if (lastPlayer == Player::White)
    {
	return Player::Black;
    } else if (lastPlayer == Player::Black) {
	return Player::White;
    } else {
	return Player::Nobody;
    }
}

std::ostream& operator<<(std::ostream& outputStream, const Model::History& history)
{
    for (size_t i = 0; i != history.eventLog.size(); ++i)
    {
	outputStream << *history.eventLog.at(i) << "\n";
    }
    return outputStream;    
}

std::istream& operator>>(std::istream& inputStream, Model::History& history)
{
    // placeholder for hard work that comes:
    
    // -> here <-
    
    return inputStream;   
}



}