// (C) Máté Gergely - gerymate@gmail.com
#ifndef MOVE_H
#define MOVE_H

#include "common.h"
#include "gameevent.h"
#include "position.h"
// #include "piece.h"
#include "game.h"
// #include "history.h"
// #include "judge.h"
#include "board.h"

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
