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
public:
    Judge(Game* theGame);
    PointerToPositionList getPossibleMovesFrom(Position& from);
    PointerToPositionList getCurrentlyPossibleMovesFrom(Position& from);
    bool isValidMove(Position& from, Position& to);
//    Player getNextPlayer() const { return nextPlayer; }
    

};

}

#endif // JUDGE_H
