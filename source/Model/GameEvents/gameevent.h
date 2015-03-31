#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include <string>
#include <memory>
#include "board.h"
#include "history.h"
#include "player.h"


namespace Model
{
    
class GameEvent
{
public:
    virtual bool execute() = 0;
    virtual bool revert() = 0;
    virtual std::string getNotation() = 0;
    Player getNextPlayer() const { return nextPlayer; }
    int getMoveNumber() const { return moveNumber; }
    static void setBoard(Board* theBoard) { board = theBoard; }
    static void setHistory(History* theHistory);
    virtual ~GameEvent();
protected:
    static Board* board;
    static History* history;

    Player nextPlayer { Player::Nobody };
    int moveNumber { 0 };

    void switchNextPlayer();
    
};

}
#endif // GAMEEVENT_H
