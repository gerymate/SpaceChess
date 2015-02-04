#include "coord.h"

#include <string>
#include <sstream>

namespace Model {

Coord::Coord(int _y, int _x, int _z) : y(_y), x(_x), z(_z) 
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