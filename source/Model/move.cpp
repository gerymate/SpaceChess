// (C) Máté Gergely - gerymate@gmail.com
#include "move.h"

#include <exception>
#include <sstream>

namespace Model
{

Move::Move(Game* theGame, const Position& theSource, const Position& theDestination, 
	 PointerToPiece thePieceAfterPromotion)
	: GameEvent{theGame}
	, source{theSource}, destination{theDestination}
	, pieceAfterPromotion{thePieceAfterPromotion} 
{
    
    
}
    

bool Move::execute()
{
    setPlayerAndMoveNumberBasedOnPreviousGameEvent();
    
    if (!game) throw std::runtime_error("Game not set when executing a Move GameEvent");
    bool success = false;
    Board* board = game->getBoard();
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
    Board* board = game->getBoard();
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

std::string Move::getNotation() const
{
    std::stringstream notation;
    notation << source << " " << destination;
    return notation.str();
}

}