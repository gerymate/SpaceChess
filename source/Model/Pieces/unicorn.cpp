// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "unicorn.h"

namespace Model
{
    
PointerToPositionList Unicorn::getPossibleMoves()
{
    return Piece::moveOrTakeTrueDiagonallyFrom(position);
}
    
    
}
