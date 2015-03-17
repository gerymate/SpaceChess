#include "board.h"

namespace Model
{

bool Board::addPiece(const Position& atField, PointerToPiece piece)
{
    bool success = false;
    if (piecesOnBoard.find(atField) == end(piecesOnBoard))
    {
	piecesOnBoard[atField] = piece;
	success = true;
    }
    return success;
}

bool Board::removePiece(const Position& atField)
{
    bool success = false;
    auto pi = piecesOnBoard.find(atField);    
    if (pi != end(piecesOnBoard))
    {
	piecesOnBoard.erase(pi);
	success = true;
    }
    return success;    
}

PointerToPiece Board::getPiece(const Position& atField)
{
    auto pi = piecesOnBoard.find(atField);
    PointerToPiece piece = nullptr;
    if (pi != end(piecesOnBoard))
    {
	piece = pi->second;
    }
    return piece;
}

    
    
    
}