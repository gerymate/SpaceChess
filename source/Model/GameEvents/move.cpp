#include "move.h"

#include <exception>
#include <sstream>

namespace Model
{
    
bool Move::execute()
{
    if (!board) throw std::runtime_error("Board not set when executing a Move GameEvent");
    bool success = false;
    pieceAtSource = board->getPiece(source);
    if (pieceAtSource) 
    {	
	success = board->removePiece(source);

	pieceTaken = board->getPiece(destination);
	if(pieceTaken)
	{
	    board->removePiece(destination);
	}
	if (pieceAfterPromotion)
	{
	    success &= board->addPiece(destination, pieceAfterPromotion);
	} else {
	    success &= board->addPiece(destination, pieceAtSource);
	}    
    }
    return success;
}

bool Move::revert()
{
    bool success = false;
    if (pieceAtSource && !board->isOccupied(source))
    {
	success = board->removePiece(destination) && board->addPiece(source, pieceAtSource);
	if (pieceTaken)
	{
	    success &= board->addPiece(destination, pieceTaken);
	}
    }
    return success;
}

std::string Move::getNotation()
{
    // valid only after execution...
    std::stringstream notation;
    notation << source
	<< (pieceTaken ? "x" : " ")
	<< destination;
    if (pieceAfterPromotion)
    {
//	notation << "=" << pieceAfterPromotion->getFigure();
    }
  return notation.str();
}

}