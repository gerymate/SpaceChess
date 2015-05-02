#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <string>
#include "position.h"
#include "fullboard.h"
#include "common.h"
#include "piece.h"

namespace Model{

class Board
{
    std::map<Position, PointerToPiece > piecesOnBoard;
public:
    Board(std::string boardDesc = "");
    bool addPiece(const Position& atField, PointerToPiece piece);
    bool removePiece(const Position& atField);
    PointerToPiece getPiece(const Position& atField);
    bool isOccupied(const Position& atField);
    FullBoard getFullBoard();

    friend std::ostream& operator<<(std::ostream& outputStream, const Model::Board& board);
    friend std::istream& operator>>(std::istream& inputStream, Model::Board& board);
    
};

}

#endif // BOARD_H
