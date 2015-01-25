#ifndef COORD_H
#define COORD_H

#include <iostream>

namespace Model {
//	A Coord stores information about a field in the board.

struct Coord
{
	// x, y, z : Place in the board (1..5) There are 5 levels of 5x5 planes
	int y, x, z;
	Coord(int _y = 1, int _x = 1, int _z = 1);
	// getColour() : Reports if the field is black (2) or white (1)
	static const int BLACK = 2;
	static const int WHITE = 1;
	const int getColour() const;

	friend std::ostream& operator<<(std::ostream& os, const Model::Coord& coord);
	friend std::istream& operator>>(std::istream& is, Model::Coord& coord);
};

}
#endif
