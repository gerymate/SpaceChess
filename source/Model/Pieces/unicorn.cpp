// (C) Máté Gergely - gerymate@gmail.com
#include "unicorn.h"

namespace Model
{
    
PointerToPositionList Unicorn::getPossibleMoves()
{
    return Piece::moveOrTakeTrueDiagonallyFrom(position);
}
    
    
}
