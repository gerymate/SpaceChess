#include "addpiece.h"

#include <exception>

namespace Model
{
    
bool AddPiece::execute()
{
    if (!board) throw std::runtime_error("Board not set when executing an AddPiece GameEvent");
    return board->addPiece(position, piece);
}

bool AddPiece::revert()
{
    return board->removePiece(position);
}

std::string AddPiece::getNotation() const
{
    return "Add piece";
}

}