// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

namespace Model
{

class Bishop : public Piece
{
    const Figure figure { Figure::Bishop };
public:
    const Figure getFigure() const override { return figure; }
    PointerToPositionList getPossibleMoves() override;
};

}
#endif // BISHOP_H
