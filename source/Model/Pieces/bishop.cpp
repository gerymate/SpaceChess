// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "bishop.h"

namespace Model
{

PointerToPositionList Bishop::getPossibleMoves()
{
    return Piece::moveOrTakePlaneDiagonallyFrom(position);
}
    
    
}
