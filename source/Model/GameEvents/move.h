// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef MOVE_H
#define MOVE_H

#include "gameevent.h"
#include "position.h"
#include "piece.h"
#include "common.h"
#include "game.h"
#include "history.h"
#include "judge.h"

namespace Model
{

class Move : public GameEvent
{
    Position source, destination;
    PointerToPiece pieceAfterPromotion, pieceTaken{nullptr}, pieceAtSource{nullptr};
public:
    Move(Game* theGame, const Position& theSource, const Position& theDestination, 
	 PointerToPiece thePieceAfterPromotion = nullptr);
    bool execute() override;
    bool revert() override;
    std::string getNotation() const override;
};

}

#endif // MOVE_H
