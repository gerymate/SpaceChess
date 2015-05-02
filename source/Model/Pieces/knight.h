#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

namespace Model
{

class Knight : public Piece
{
    const Figure figure { Figure::Knight };
public:
    const Figure getFigure() const override { return figure; }
    PointerToPositionList getPossibleMoves() override;
};

}
#endif // KNIGHT_H
