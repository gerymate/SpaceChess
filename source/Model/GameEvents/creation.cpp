#include "creation.h"

namespace Model
{
    
Creation::Creation(Game* theGame) : GameEvent{theGame}
{
    player = Player::Black;
    moveNumber = 0;
}

bool Creation::execute()
{
    return true;
}

bool Creation::revert()
{
    return false;
}

std::string Creation::getNotation() const
{
    return "Game created.";
}

}