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

void GameEvent::switchNextPlayer()
{
    if (Player::White == nextPlayer)
    {
	nextPlayer = Player::Black;
    } else if (Player::Black == nextPlayer)
    {
	nextPlayer = Player::White;
    }
}


Board* GameEvent::board = nullptr;
History* GameEvent::history = nullptr;

}