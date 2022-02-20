// (C) Máté Gergely - gerymate@gmail.com
#include "queen.h"

namespace Model
{
    
PointerToPositionList Queen::getPossibleMoves()
{
    PointerToPositionList possibleMoves { moveOrTakeTrueDiagonallyFrom(position) };
    PointerToPositionList straights { moveOrTakeStraightFrom(position) };
    PointerToPositionList planeDiagonals { moveOrTakePlaneDiagonallyFrom(position) };
    
    possibleMoves->splice(possibleMoves->begin(), *straights);
    possibleMoves->splice(possibleMoves->begin(), *planeDiagonals);
    
    return possibleMoves;
}
    
    
}
