// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#ifndef FIELD_H
#define FIELD_H

#include<iostream>
#include "position.h"
#include "player.h"
#include "figure.h"

namespace Model {

//	Field holds information about a field in the chessboard
struct Field
{
	Player owner;
	Figure figure;
	Position position;
	Field(Player _owner = Player::Nobody, Figure _figure = Figure::None, Position _position = Position());	

	friend std::ostream& operator<<(std::ostream& os, const Field& field);
	friend std::istream& operator>>(std::istream& is, Field& field);
};

}
#endif
