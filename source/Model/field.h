#ifndef FIELD_H
#define FIELD_H

#include<iostream>
#include "coord.h"

namespace Model {
    
//	Field holds information about a field in the chessboard
struct Field
{
	int owner;	// 0..2
	/* 0 - noone
	 * 1 - white
	 * 2 - black
	*/
	int figure;	// 0..7 should be an enum?
	/* 0 - none
	 * 1 - king
	 * 2 - queen
	 * 3 - rook
	 * 4 - bishop
	 * 5 - knight
	 * 6 - unicorn
	 * 7 - pawn
	*/
	Coord place;
	Field(int _owner = 0, int _figure = 0, Coord _place = Coord());	

	friend std::ostream& operator<<(std::ostream& os, const Field& field);
	friend std::istream& operator>>(std::istream& is, Field& field);
};

}
#endif
