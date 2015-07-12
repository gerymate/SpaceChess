// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef UNICORN_H
#define UNICORN_H

#include "piece.h"

namespace Model
{

class Unicorn : public Piece
{
    const Figure figure { Figure::Unicorn };
public:
    const Figure getFigure() const override { return figure; }
    PointerToPositionList getPossibleMoves() override;
};

}
#endif // UNICORN_H
