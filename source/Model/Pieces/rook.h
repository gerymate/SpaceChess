#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

namespace Model
{

class Rook : public Piece
{
    const Figure figure { Figure::Rook };
public:
    const Figure getFigure() const override { return figure; }
};

}
#endif // ROOK_H
