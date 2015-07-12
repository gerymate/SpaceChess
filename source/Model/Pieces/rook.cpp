// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "rook.h"

namespace Model
{

PointerToPositionList Rook::getPossibleMoves()
{
    return Piece::moveOrTakeStraightFrom(position);
}
    
  
}
