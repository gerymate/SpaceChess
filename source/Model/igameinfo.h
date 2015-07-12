// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef IGAMEINFO_H
#define IGAMEINFO_H

#include "common.h"
#include "gamestate.h"
#include "history.h"
#include "judge.h"
#include "board.h"

namespace Model
{

// Read-only interface for Game
class IGameInfo
{
public:
    virtual GameState getGameState() const = 0;
    virtual PointerToPositionList getCurrentlyPossibleMovesFrom(Position& from) const = 0;
    virtual Player getNextPlayer() const = 0;
    virtual History* getHistory() const = 0;
    virtual Judge* getJudge() const = 0;
    virtual Board* getBoard() const = 0;
};

}
#endif // IGAMEINFO_H
