#include "judge.h"

namespace Model 
{

    
Judge::Judge(Board* theBoard, History* theHistory) : board{theBoard}, history{theHistory}
{
}

PointerToPositionList Judge::getPossibleMovesFrom(Position& from)
{
    if (!board->isOccupied(from))
    {
	return nullptr;
    }
    
    PointerToPositionList basicPossibleMoves = board->getPiece(from)->getPossibleMoves();
    
    return basicPossibleMoves;
    
}

bool Judge::isValidMove(Position& from, Position& to)
{
    bool validMove = false;
    auto possibleMoves = getPossibleMovesFrom(from);
    if (possibleMoves != nullptr)
    {
	validMove = std::find(possibleMoves->begin(), possibleMoves->end(), to) != possibleMoves->end();
    }
    return validMove;
}




}