#ifndef FIELD_H
#define FIELD_H

#include<iostream>
#include "coord.h"
#include "player.h"
#include "figure.h"

namespace Model {

//	Field holds information about a field in the chessboard
struct Field
{
	Player owner;
	Figure figure;
	Coord place;
	Field(Player _owner = Player::Nobody, Figure _figure = Figure::None, Coord _place = Coord());	

	friend std::ostream& operator<<(std::ostream& os, const Field& field);
	friend std::istream& operator>>(std::istream& is, Field& field);
};

}
#endif
