#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include <string>
#include <memory>
#include "board.h"
#include "history.h"

namespace Model
{

class GameEvent
{
public:
    virtual bool execute() = 0;
    virtual bool revert() = 0;
    virtual std::string getNotation() = 0;
    static void setBoard(Board* theBoard) { board = theBoard; }
    static void setHistory(History* theHistory);
    virtual ~GameEvent();
protected:
    static Board* board;
    static History* history;
};

using PointerToGameEvent = std::shared_ptr<GameEvent>;

}
#endif // GAMEEVENT_H
