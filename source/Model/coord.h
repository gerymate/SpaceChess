#ifndef COORD_H
#define COORD_H

#include <iostream>
#include <string>
#include <vector>

namespace Model {
//	A Coord stores information about a field in the board.

struct Coord
{
	// x, y, z : Place in the board (0..4) There are 5 levels of 5x5 planes
	// would prefer chess terminology, eg. level, file, rank, ...
	int y, x, z;
	Coord(int _y = 0, int _x = 0, int _z = 0);
	// getColour() : Reports if the field is black (2) or white (1)
	static const int BLACK = 2;
	static const int WHITE = 1;
	const int getColour() const;
	bool operator==(const Coord &other) const;
	bool operator!=(const Coord &other) const;
	std::string getNotation() const;
	bool isOnTheBoard() const;
};

std::ostream& operator<<(std::ostream& os, const Model::Coord& coord);
std::istream& operator>>(std::istream& is, Model::Coord& coord);


}
#endif
