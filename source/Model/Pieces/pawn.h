#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

namespace Model
{

class Pawn : public Piece
{
    const Figure figure { Figure::Pawn };
    
    PointerToPositionList getMovePossibilities();
    PointerToPositionList getTakePossibilities();
public:
    const Figure getFigure() const override { return figure; }
    PointerToPositionList getPossibleMoves() override;
    PointerToPositionList getPossibleTakes() override;
};

}
#endif // PAWN_H
