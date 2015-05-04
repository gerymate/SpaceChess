#include "move.h"

#include <exception>
#include <sstream>

namespace Model
{
    
bool Move::execute()
{
    setPlayerBasedOnPreviousGameEvent();
    updateMoveNumber();
    
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

void Move::updateMoveNumber()
{
    if (player == Player::White)
    {
	++moveNumber;
    }
}

std::string Move::getNotation() const
{
    // valid only after execution...
    std::stringstream notation;
    notation << moveNumber << " ";
    if (player == Player::Black) 
    {
	notation << "... ";
    }
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