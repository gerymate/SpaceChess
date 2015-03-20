#include "creation.h"

namespace Model
{
    
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

std::string Creation::getNotation()
{
    return "Game created.";
}

}