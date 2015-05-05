#include "judge.h"

namespace Model 
{

    
Judge::Judge(Game* theGame) : game{theGame}, board{theGame->getBoard()}, history{theGame->getHistory()}
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

PointerToPositionList Judge::getCurrentlyPossibleMovesFrom(Position& from)
{
    if (!board->isOccupied(from) || board->getPiece(from)->getPlayer() != history->getNextPlayer())
    {
	return nullptr;
    } else {
	return getPossibleMovesFrom(from);
    }
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