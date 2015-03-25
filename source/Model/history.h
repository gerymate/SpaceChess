#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <memory>
#include "player.h"
#include "board.h"
#include "common.h"

namespace Model
{

class History
{
    Board* board;
    std::vector<PointerToGameEvent> eventLog;
    size_t indexOfNextEvent {0};
    Player nextPlayer { Player::Nobody };
public:
    History(Board* theBoard);
    void addEvent(PointerToGameEvent& event) { eventLog.push_back(event); }
    PointerToGameEvent getCurrentEvent() const { return eventLog.at(indexOfNextEvent - 1); }
    void reset() { indexOfNextEvent = 1; }
    bool actualize();
    void clearFuture();
    bool stepForward();
    bool stepBack();
    Player getNextPlayer() const { return nextPlayer; }
};

}

#endif // HISTORY_H
