#ifndef MOVE_H
#define MOVE_H

#include "gameevent.h"
#include "position.h"
#include "piece.h"

namespace Model
{

class Move : public GameEvent
{
    Position source, destination;
public:
    Move(const Position& theSource, const Position& theDestination) 
	: source(theSource), destination(theDestination) {};
    bool execute() override;
    bool revert() override;
    std::string getNotation() override;
};

}

#endif // MOVE_H
