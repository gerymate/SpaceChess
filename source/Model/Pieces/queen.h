// (C) Máté Gergely - gerymate@gmail.com
#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

namespace Model
{

class Queen : public Piece
{
    const Figure figure { Figure::Queen };
public:
    const Figure getFigure() const override { return figure; }
    PointerToPositionList getPossibleMoves() override;
};

}
#endif // QUEEN_H
