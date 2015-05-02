#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

namespace Model
{

class Pawn : public Piece
{
    const Figure figure { Figure::Pawn };
public:
    const Figure getFigure() const override { return figure; }
    PointerToPositionList getPossibleMoves() override;    
};

}
#endif // PAWN_H
