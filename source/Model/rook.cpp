// (C) Máté Gergely - gerymate@gmail.com
#include "rook.h"

namespace Model
{

PointerToPositionList Rook::getPossibleMoves()
{
    return Piece::moveOrTakeStraightFrom(position);
}
    
  
}
