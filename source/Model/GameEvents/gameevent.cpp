#include "gameevent.h"

namespace Model
{

Board* GameEvent::board = nullptr;
History* GameEvent::history = nullptr;
    
void GameEvent::setHistory(History* theHistory)
{
    history = theHistory;
}

    
GameEvent::~GameEvent()
{

}

void GameEvent::setPlayerBasedOnPreviousGameEvent()
{
    Model::Player previousPlayer = history->getPlayerForLastEvent();
    if (Player::White == previousPlayer)
    {
	player = Player::Black;
    } else if (Player::Black == previousPlayer)
    {
	player = Player::White;
    } else {
	player = Player::Nobody;
    }
}

std::ostream& operator<<(std::ostream& outputStream, const Model::GameEvent& gameEvent)
{
    outputStream << gameEvent.getNotation();
    return outputStream;
}


}