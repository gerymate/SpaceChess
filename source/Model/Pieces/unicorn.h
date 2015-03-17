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
};

}
#endif // UNICORN_H
