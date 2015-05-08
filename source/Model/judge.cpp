#include "judge.h"

namespace Model 
{
    
Judge::Judge(Game* theGame) : game{theGame}, board{theGame->getBoard()}, history{theGame->getHistory()}
{
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

PointerToPositionList Judge::getPossibleMovesFrom(Position& from)
{
    if (!board->isOccupied(from))
    {
	return nullptr;
    }
    
    PointerToPositionList basicPossibleMoves = board->getPiece(from)->getPossibleMoves();
    
    filterTargetsForNotInCheckAfter(from, basicPossibleMoves);
    
    return basicPossibleMoves;   
}

void Judge::filterTargetsForNotInCheckAfter(Position& from, PointerToPositionList targets)
{
    // generate a list of moves for all targets
    // for each move:
    // execute it
    // check if the king is in check and remove the corresponding targets
    // revert the move

}

bool Judge::isInCheck(Player player)
{
    // get king's position
    Position theKingsPosition = board->find(player, Figure::King);

    // generate a list of all pieces of the other side
    Player otherPlayer { player == Player::White ? Player::Black : Player::White };
    PointerToPointerToPieceList enemies { board->getAllPiecesFor(otherPlayer) };

    // for each piece get possible *takes* and check if the king's position is among those.
    for (const auto& enemy : *enemies)
    {
	PointerToPositionList canTakeAt { enemy->getPossibleTakes() };
	for (const Position& pos : *canTakeAt)
	{
	    if (pos == theKingsPosition) return true;
	}
    }
    return false;
}




}