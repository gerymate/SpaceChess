#ifndef PAWN_H
#define PAWN_H

#include "Model/piece.h"

namespace Model
{

class Pawn : public Piece
{
    const Figure figure { Figure::Pawn };
public:
    const Figure getFigure() const override { return figure; }
};

}
#endif // PAWN_H
