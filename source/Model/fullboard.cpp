#include "fullboard.h"

using std::vector;

namespace Model {

FullBoard::FullBoard() : space(5, vector<vector<Field> >(5, vector<Field>(5)))
{
	for(int y = 0; y != 5; ++y) {
		for(int x = 0; x != 5; ++x) {
			for(int z = 0; z != 5; ++z) {
				space[y][x][z] = Field(Player::Nobody, Figure::None, Position(y+1, x+1, z+1));
			}
		}
	}
}

Field& FullBoard::at(const Position& position) {
	return space.at(position.getLevel()-1).at(position.getFile()-1).at(position.getRank()-1);
	//[place.y][place.x][place.z];
}

std::ostream& operator<<(std::ostream& os, const Model::FullBoard& board)
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

std::istream& operator>>(std::istream& is, Model::FullBoard& board) {
	for(int y = 4; y >= 0; --y) {
		for(int z = 0; z != 5; ++z) {
			for(int x = 0; x != 5; ++x) {
				board.space[y][x][z] = Field(Player::Nobody, Figure::None, Position(y+1, x+1, z+1));
				is >> board.space[y][x][z];
			}
		}
	}	
	return is;
}

}