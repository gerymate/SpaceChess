#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <memory>
#include "player.h"
#include "board.h"

namespace Model
{
    
class GameEvent;
using PointerToGameEvent = std::shared_ptr<GameEvent>;

class History
{
    Board* board;
    std::vector<PointerToGameEvent> eventLog;
    std::vector<PointerToGameEvent>::iterator current;
    Player nextPlayer { Player::Nobody };
public:
    History(Board* theBoard);
    void addEvent(PointerToGameEvent& event) { eventLog.push_back(event); }
    PointerToGameEvent getCurrentEvent() const { return *(current - 1); }
    void reset() { current = eventLog.begin() + 1; }
    bool actualize();
    void clearFuture();
    bool stepForward();
    bool stepBack();
    Player getNextPlayer() const { return nextPlayer; }
};

}

#endif // HISTORY_H
