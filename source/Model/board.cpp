#include "board.h"

using std::vector;

Board::Board() : space(5, vector<vector<Field> >(5, vector<Field>(5)))
{
	for(int y = 0; y != 5; ++y) {
		for(int x = 0; x != 5; ++x) {
			for(int z = 0; z != 5; ++z) {
				space[y][x][z] = Field(0, 0, Coord(y, x, z));
			}
		}
	}
}

Field& Board::at(const Coord& place) {
	return space[place.y - 1][place.x - 1][place.z - 1];
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{	
	for(int y = 0; y != 5; ++y) {
		for(int z = 0; z != 5; ++z) {
			for(int x = 0; x != 5; ++x) {
				os << board.space[4 - y][x][z]; 
				// board y is different from screen y
			}
			os << "\t";
		}
		os << "\n";
	}
    return os;
}

std::istream& operator>>(std::istream& is, Board& board) {
	for(int y = 4; y >= 0; --y) {
		for(int z = 0; z != 5; ++z) {
			for(int x = 0; x != 5; ++x) {
				board.space[y][x][z] = Field(0, 0, Coord(y, x, z));
				is >> board.space[y][x][z];
			}
		}
	}	
	return is;
}
