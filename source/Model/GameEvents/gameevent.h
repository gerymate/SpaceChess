#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include <string>
#include <memory>
#include "board.h"

namespace Model
{

class History;
    
class GameEvent
{
    PointerToBoard board;
public:
    virtual bool execute() = 0;
    virtual void revert() = 0;
    virtual std::string getNotation() = 0;
    void setBoard(PointerToBoard theBoard) { board = theBoard; }
    void setHistory(History& theHistory);
    virtual ~GameEvent();
};

}
#endif // GAMEEVENT_H
