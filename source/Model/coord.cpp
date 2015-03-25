#include "coord.h"

#include <string>
#include <sstream>
#include "position.h"

namespace Model {
    
Coord::Coord(int _y, int _x, int _z) : y(_y), x(_x), z(_z) 
{
}

Coord::Coord(const Position& pos) : y{pos.getLevel()}, x{pos.getFile()}, z{pos.getRank()}
{
}


const int Coord::getColour() const 
{
	return ((x + y + z) % 2) ? 1 : 2; // is that field black(2) or white(1) ?
}

bool Coord::operator==(const Coord& other) const
{
    return (y == other.y) && (x == other.x) && (z == other.z);
}

bool Coord::operator!=(const Coord& other) const
{
    return ! operator==(other);

}


std::string Coord::getNotation() const
{
    std::string notation;
    if (isOnTheBoard())
    {
	const char* XNotation = "abcde";
	const char* YNotation = "ABCDE";
	const char* ZNotation = "12345";
	notation += YNotation[y];
	notation += XNotation[x];
	notation += ZNotation[z];
    }
    return notation;
}

bool Coord::isOnTheBoard() const
{
    return x >= 0 && x <= 4 && y >= 0 && y <= 4 && z >= 0 && z <= 4;
}


std::ostream& operator<<(std::ostream& os, const Model::Coord& coord)
{
	os << coord.y << coord.x << coord.z;
	return os;
}

std::istream& operator>>(std::istream& is, Model::Coord& coord)
{
	char y, x, z;
	is >> y >> x >> z;
	std::string Y(1, y), X(1, x), Z(1, z);
	std::istringstream ys(Y), xs(X), zs(Z);
	ys >> coord.y;
	xs >> coord.x;
	zs >> coord.z;
	return is;
}

}