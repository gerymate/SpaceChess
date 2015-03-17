#include "addpiece.h"

#include <exception>

namespace Model
{
    
bool AddPiece::execute()
{
    if (!board) throw std::runtime_error("Board not set when executing an AddPiece GameEvent");
    return executed = board->addPiece(position, piece);
}

bool AddPiece::revert()
{
    bool success = false;
    if (executed) 
    {
	success = board->removePiece(position);
	executed = !success;
    }
    return success;
}

std::string AddPiece::getNotation()
{
    return "Add piece";
}

}