#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <memory>
#include "player.h"
#include "board.h"
#include "gameevent.h"
#include "common.h"

namespace Model
{

class History
{
    Board* board;
    std::vector<PointerToGameEvent> eventLog;
    size_t indexOfNextEvent {0};
public:
    History(Board* theBoard);
    void addEvent(PointerToGameEvent& event);
    PointerToGameEvent getCurrentEvent() const;
    void reset();
    bool actualize();
    void clearFuture();
    bool stepForward();
    bool stepBack();
    Player getPlayerForLastEvent() const;
    Player getNextPlayer() const;
    
    friend std::ostream& operator<<(std::ostream& outputStream, const Model::History& history);
    friend std::istream& operator>>(std::istream& inputStream, Model::History& history);

};

}

#endif // HISTORY_H
