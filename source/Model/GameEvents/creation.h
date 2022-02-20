// (C) Máté Gergely - gerymate@gmail.com
#ifndef CREATION_H
#define CREATION_H

#include "gameevent.h"

namespace Model
{

class History;
    
class Creation : public GameEvent
{
public:
    Creation(Game* theGame);
    bool execute() override;
    bool revert() override;
    std::string getNotation() const override;
};

}

#endif // CREATION_H
