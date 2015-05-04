#ifndef CREATION_H
#define CREATION_H

#include "gameevent.h"

namespace Model
{

class History;
    
class Creation : public GameEvent
{
    Board* board;
    History* history;
public:
    Creation(Board* theBoard, History* theHistory);
    bool execute() override;
    bool revert() override;
    std::string getNotation() override;
};

}

#endif // CREATION_H
