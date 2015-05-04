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

Board* GameEvent::board = nullptr;
History* GameEvent::history = nullptr;

}