#include "move.h"

#include <exception>

namespace Model
{
    
bool Move::execute()
{
    if (!board) throw std::runtime_error("Board not set when executing a Move GameEvent");
    bool success = false;
    PointerToPiece piece = board->getPiece(source);
    if ( piece && !board->isOccupied(destination) )
    {
	success = board->removePiece(source) && board->addPiece(destination, piece);
    }
    return success;
}

bool Move::revert()
{
    bool success = false;
    PointerToPiece piece = board->getPiece(destination);
    if (piece && !board->isOccupied(source))
    {
	success = board->removePiece(destination) && board->addPiece(source, piece);
    }
    return success;
}

std::string Move::getNotation()
{
    return "Move source -> dest";
}

}