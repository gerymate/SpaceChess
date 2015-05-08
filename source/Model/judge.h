#ifndef JUDGE_H
#define JUDGE_H

#include <vector>
#include <memory>
#include <algorithm>
#include "common.h"
#include "player.h"
#include "board.h"
#include "history.h"
#include "game.h"

namespace Model
{

class Judge
{
    Game* game;
    Board* board;
    History* history;
    PointerToPositionList getPossibleMovesFrom(Position& from);
    void filterTargetsForNotInCheckAfter(Position& from, PointerToPositionList targets);

public:
    Judge(Game* theGame);
    PointerToPositionList getCurrentlyPossibleMovesFrom(Position& from);
    bool isValidMove(Position& from, Position& to);
    bool isInCheck(Player player);

};

}

#endif // JUDGE_H
