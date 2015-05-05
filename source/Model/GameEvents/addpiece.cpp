#include "addpiece.h"

#include <exception>

namespace Model
{

AddPiece::AddPiece(const Position& thePosition, PointerToPiece thePiece): GameEvent(nullptr), position(thePosition), piece(thePiece)
{

}

bool AddPiece::execute()
{
    if (!game) throw std::runtime_error("Game not set when executing an AddPiece GameEvent");
    return game->getBoard()->addPiece(position, piece);
}

bool AddPiece::revert()
{
    return game->getBoard()->removePiece(position);
}

std::string AddPiece::getNotation() const
{
    return "Add piece";
}

}