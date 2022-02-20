// (C) Máté Gergely - gerymate@gmail.com
#ifndef JUDGE_H
#define JUDGE_H

#include <vector>
#include "common.h"
#include "player.h"

namespace Model
{

class Judge
{
    Game* game;
    Board* board;
    History* history;
    PointerToPositionList getPossibleMovesFrom(const Position& from);
    PointerToPositionList filterTargetsForNotInCheckAfter(const Position& from, PointerToPositionList targets);

public:
    Judge(Game* theGame);
    PointerToPositionList getCurrentlyPossibleMovesFrom(Position& from);
    bool isValidMove(Position& from, Position& to);
    bool isInCheck(Player player);
    bool canMove(Player player);

};

}

#endif // JUDGE_H
