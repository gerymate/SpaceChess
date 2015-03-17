#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <memory>
#include "position.h"
#include "piece.h"
#include "fullboard.h"

namespace Model{

using PointerToPiece = std::shared_ptr<Piece>;
    
class Board
{
    std::map<Position, PointerToPiece > piecesOnBoard;
public:
    bool addPiece(const Position& atField, PointerToPiece piece);
    PointerToPiece getPiece(const Position& atField);
    FullBoard getFullBoard() const;
};

}

#endif // BOARD_H
