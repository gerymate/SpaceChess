#ifndef KING_H
#define KING_H

#include "piece.h"

namespace Model
{

class King : public Piece
{
    const Figure figure { Figure::King };
public:
    const Figure getFigure() const override { return figure; };
    PositionList getPossibleMoves();
};

}
#endif // KING_H
