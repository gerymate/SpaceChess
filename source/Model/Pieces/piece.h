#ifndef PIECE_H
#define PIECE_H

#include <functional>
#include "common.h"
#include "player.h"
#include "figure.h"
#include "position.h"
#include "board.h"

namespace Model {

class Piece
{
public:
    static PointerToPiece generatePiece(const std::string& PieceDesc, Board* theBoard);
    virtual ~Piece();
    const Player getPlayer() const { return player; };
    virtual const Figure getFigure() const = 0;
    virtual PointerToPositionList getPossibleMoves() = 0;
    const Position& getPosition() const { return position; };
    void setPosition(const Position& thePosition) { position = thePosition; }
protected:
    Player player { Player::Nobody };
    Position position;
    Board* board;
    bool canMoveTo(const Position& position);
    bool canTakeAt(const Position& position);
    bool canMoveToOrTakeAt(const Position& position);
    void filterForMove(PointerToPositionList targets);
    void filterForTake(PointerToPositionList targets);
    void filterForMoveOrTake(PointerToPositionList targets);
    PointerToPositionList moveOrTakeStraightFrom(const Position& position);
    PointerToPositionList moveOrTakePlaneDiagonallyFrom(const Position& position);
    PointerToPositionList moveOrTakeTrueDiagonallyFrom(const Position& position);
    
    using DirectionFunction = std::function<Position(const Position&)>;
    using DirectionFunctionList = std::list<DirectionFunction>;
    void addPositionsFromSourceInDirection(PointerToPositionList positionList, 
					   const Position& sourcePosition,
					   DirectionFunction directionFunction);
    void addPositionsFromSourceInManyDirections(PointerToPositionList positionList,
						const Position& sourcePosition,
						DirectionFunctionList directions);
    
private:
    static PointerToPiece generatePieceFromString(std::string PieceDesc, Board* theBoard);
};


}
#endif // PIECE_H
