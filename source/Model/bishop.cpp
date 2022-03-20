// (C) Máté Gergely - gerymate@gmail.com
#include "bishop.h"

namespace Model
{

PointerToPositionList Bishop::getPossibleMoves()
{
    return Piece::moveOrTakePlaneDiagonallyFrom(position);
}
    
    
}
