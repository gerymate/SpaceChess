#ifndef BISHOP_H
#define BISHOP_H

#include "Model/piece.h"

namespace Model
{

class Bishop : public Piece
{
    const Figure figure { Figure::Bishop };
public:
    const Figure getFigure() const override { return figure; }
};

}
#endif // BISHOP_H
