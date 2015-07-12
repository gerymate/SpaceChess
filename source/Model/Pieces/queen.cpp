// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
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
