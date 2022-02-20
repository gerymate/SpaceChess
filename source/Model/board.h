// (C) Máté Gergely - gerymate@gmail.com
#ifndef BOARD_H
#define BOARD_H

#include "common.h"
#include <map>
#include "position.h"
#include "fullboard.h"
#include "piece.h"
#include "iboardinfo.h"

namespace Model{

class Board : public IBoardInfo
{
    std::map<Position, PointerToPiece > piecesOnBoard;
public:
    Board(std::string boardDesc = "");
    virtual ~Board();
    bool addPiece(const Position& atField, PointerToPiece piece);
    bool removePiece(const Position& atField);
    PointerToPiece getPiece(const Position& atField) const override;
    bool isOccupied(const Position& atField) override;
    FullBoard getFullBoard() const override;
    Position find(Player player, Figure figure) override;
    PointerToPointerToPieceList getAllPiecesFor(Player player) override;

    friend std::ostream& operator<<(std::ostream& outputStream, const Model::Board& board);
    friend std::istream& operator>>(std::istream& inputStream, Model::Board& board);
    
};

}

#endif // BOARD_H
