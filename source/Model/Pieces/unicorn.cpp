#include "unicorn.h"

namespace Model
{
    
PointerToPositionList Unicorn::getPossibleMoves()
{
    return Piece::moveOrTakeTrueDiagonallyFrom(position);
}
    
    
}
