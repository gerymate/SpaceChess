#include "judge.h"

#include <algorithm>
#include "gameevent.h"
#include "game.h"

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

PointerToPositionList Judge::getPossibleMovesFrom(const Position& from)
{
    if (!board->isOccupied(from))
    {
	return nullptr;
    }
    
    PointerToPositionList basicPossibleMoves { board->getPiece(from)->getPossibleMoves() };
    
    PointerToPositionList possibleMoves { filterTargetsForNotInCheckAfter(from, basicPossibleMoves) };
    
    return possibleMoves;   
}

PointerToPositionList Judge::filterTargetsForNotInCheckAfter(const Position& from, PointerToPositionList targets)
{
    Player player {board->getPiece(from)->getPlayer()};
    PointerToPositionList goodTargets = std::make_shared<PositionList>();
    
    // generate a map of target - move event pairs
    std::map<Position, PointerToGameEvent> possibleMoves;
    for (const Position& dest : *targets)
    {
	possibleMoves.insert(std::make_pair(dest, GameEvent::generateMove(from, dest, game)));
    }
    // for each move:
    for (auto aMove : possibleMoves)
    {
    // add to the history
	history->addEvent(aMove.second);
    // execute it
	history->stepForward();
    // check if the king is in check and remove the corresponding targets
	if (!isInCheck(player))
	{
	    goodTargets->push_back(aMove.first);
	}
    // revert the move
	history->stepBack();
    // remove it from the history
	history->clearFuture();
    }
    return goodTargets;
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

bool Judge::canMove(Player player)
{
    // make a list of positions for all pieces for the player
    PointerToPointerToPieceList ownPieces { board->getAllPiecesFor(player) };
    PointerToPositionList placeOfOwnPieces = std::make_shared<PositionList>();
    for (const PointerToPiece& ownPiece : *ownPieces)
    {
	placeOfOwnPieces->push_back(ownPiece->getPosition());
    }
    
    // check if there are any possible moves from those places
    for (const Position& position : *placeOfOwnPieces)
    {
	PointerToPositionList possibleMoves { getPossibleMovesFrom(position) };
	if (possibleMoves && !possibleMoves->empty()) return true;
    }
    return false;
}




}