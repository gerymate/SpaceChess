#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include <string>
#include <memory>
#include "common.h"
#include "board.h"
#include "player.h"
#include "history.h"

namespace Model
{
    
class GameEvent
{
public:
    virtual bool execute() = 0;
    virtual bool revert() = 0;
    virtual std::string getNotation() const = 0;
    Player getPlayer() const { return player; }
    int getMoveNumber() const { return moveNumber; }
    static void setBoard(Board* theBoard) { board = theBoard; }
    static void setHistory(History* theHistory);
    virtual ~GameEvent();
    
    friend std::ostream& operator<<(std::ostream& outputStream, const Model::GameEvent& gameEvent);
protected:
    static Board* board;
    static History* history;

    Player player { Player::Nobody };
    int moveNumber { 0 };

    void setPlayerBasedOnPreviousGameEvent();
    
};

}
#endif // GAMEEVENT_H
