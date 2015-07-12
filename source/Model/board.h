// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef BOARD_H
#define BOARD_H

#include "common.h"
#include <map>
#include "position.h"
#include "fullboard.h"
#include "piece.h"

namespace Model{

class Board
{
    std::map<Position, PointerToPiece > piecesOnBoard;
public:
    Board(std::string boardDesc = "");
    bool addPiece(const Position& atField, PointerToPiece piece);
    bool removePiece(const Position& atField);
    PointerToPiece getPiece(const Position& atField) const;
    bool isOccupied(const Position& atField);
    FullBoard getFullBoard() const;
    Position find(Player player, Figure figure);
    PointerToPointerToPieceList getAllPiecesFor(Player player);

    friend std::ostream& operator<<(std::ostream& outputStream, const Model::Board& board);
    friend std::istream& operator>>(std::istream& inputStream, Model::Board& board);
    
};

}

#endif // BOARD_H
