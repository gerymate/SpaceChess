#ifndef PIECE_H
#define PIECE_H

#include "player.h"
#include "figure.h"
#include "position.h"
#include <string>

namespace Model {

class Piece
{
public:
    static PointerToPiece generatePiece(std::string);
    virtual ~Piece();
    const Player getPlayer() const { return player; };
    virtual const Figure getFigure() const = 0;
    const Position& getPosition() const { return position; };
    void setPosition(const Position& thePosition) { position = thePosition; }
protected:
    Player player { Player::Nobody };
    Position position;
};


}
#endif // PIECE_H
