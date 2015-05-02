#include "bishop.h"

namespace Model
{

PointerToPositionList Bishop::getPossibleMoves()
{
    return Piece::moveOrTakePlaneDiagonallyFrom(position);
}

    
    
}
