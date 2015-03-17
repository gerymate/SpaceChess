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
};

}
#endif // QUEEN_H
