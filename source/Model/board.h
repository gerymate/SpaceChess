#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <memory>
#include "position.h"
#include "Model/Pieces/piece.h"
#include "fullboard.h"

namespace Model{

using PointerToPiece = std::shared_ptr<Piece>;

class Board
{
    std::map<Position, PointerToPiece > piecesOnBoard;
public:
    bool addPiece(const Position& atField, PointerToPiece piece);
    bool removePiece(const Position& atField);
    PointerToPiece getPiece(const Position& atField);
    FullBoard getFullBoard() const;
};

using PointerToBoard = std::shared_ptr<Board>;


}

#endif // BOARD_H
