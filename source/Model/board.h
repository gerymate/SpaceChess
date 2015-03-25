#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <memory>
#include "position.h"
#include "Model/Pieces/piece.h"
#include "fullboard.h"
#include "common.h"

namespace Model{

class Board
{
    std::map<Position, PointerToPiece > piecesOnBoard;
public:
    bool addPiece(const Position& atField, PointerToPiece piece);
    bool removePiece(const Position& atField);
    PointerToPiece getPiece(const Position& atField);
    bool isOccupied(const Position& atField);
    FullBoard getFullBoard();
};

}

#endif // BOARD_H
