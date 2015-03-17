#ifndef PIECE_H
#define PIECE_H

#include "player.h"
#include "figure.h"
#include "position.h"

namespace Model {

class Piece
{
public:
    virtual ~Piece();
    const Player getPlayer() const { return player; };
    virtual const Figure getFigure() const = 0;
    const Position& getPosition() const { return position; };
protected:
    Player player { Player::Nobody };
    Position position;
};

}
#endif // PIECE_H
