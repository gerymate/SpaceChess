#include "creation.h"

namespace Model
{
    
Creation::Creation(Board* theBoard, History* theHistory) 
    : board{theBoard}, history{theHistory}
{
    player = Player::Black;
    moveNumber = 1;
}

bool Creation::execute()
{
    setBoard(board);
    setHistory(history);
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