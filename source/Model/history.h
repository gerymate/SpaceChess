// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include "common.h"
#include "player.h"

namespace Model
{

class History
{
    Game* game;
    Board* board;
    std::vector<PointerToGameEvent> eventLog;
    size_t indexOfNextEvent {0};
public:
    History(Game* theGame);
    void addEvent(PointerToGameEvent& event);
    PointerToGameEvent getCurrentEvent() const;
    void reset();
    bool actualize();
    void clearFuture();
    bool stepForward();
    bool stepBack();
    Player getPlayerForLastEvent() const;
    int getMoveNumberForLastEvent() const;
    Player getNextPlayer() const;
    
    friend std::ostream& operator<<(std::ostream& outputStream, const Model::History& history);
    friend std::istream& operator>>(std::istream& inputStream, Model::History& history);

};

}

#endif // HISTORY_H
