// (C) Máté Gergely - gerymate@gmail.com
#ifndef IBOARDINFO_H
#define IBOARDINFO_H

#include "common.h"
#include <map>
#include "position.h"
#include "fullboard.h"
#include "piece.h"

namespace Model{

// read-only interface for Board
class IBoardInfo
{
public:
    virtual PointerToPiece getPiece(const Position& atField) const = 0;
    virtual bool isOccupied(const Position& atField) = 0;
    virtual FullBoard getFullBoard() const = 0;
    virtual Position find(Player player, Figure figure) = 0;
    virtual PointerToPointerToPieceList getAllPiecesFor(Player player) = 0;
    
};

}

#endif // IBOARDINFO_H
