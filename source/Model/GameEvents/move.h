#ifndef MOVE_H
#define MOVE_H

#include "gameevent.h"
#include "position.h"
#include "piece.h"
#include "common.h"

namespace Model
{

class Move : public GameEvent
{
    Position source, destination;
    PointerToPiece pieceAfterPromotion, pieceTaken{nullptr}, pieceAtSource{nullptr};
public:
    Move(const Position& theSource, const Position& theDestination, 
	 PointerToPiece thePieceAfterPromotion = nullptr) 
	: source{theSource}, destination{theDestination}, pieceAfterPromotion{thePieceAfterPromotion} {}
    bool execute() override;
    bool revert() override;
    std::string getNotation() override;
};

}

#endif // MOVE_H
