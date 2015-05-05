#ifndef ADDPIECE_H
#define ADDPIECE_H

#include "gameevent.h"
#include "position.h"
#include "piece.h"
/*
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "unicorn.h"
#include "pawn.h"
*/

namespace Model
{

class AddPiece : public GameEvent
{
    Position position;
    PointerToPiece piece;
public:
    AddPiece(const Position& thePosition, PointerToPiece thePiece);
    bool execute() override;
    bool revert() override;
    std::string getNotation() const override;
};

}

#endif // ADDPIECE_H
