#ifndef FULLBOARD_H
#define FULLBOARD_H

#include<vector>
#include "field.h"
#include "coord.h"

namespace Model {
    
//	A Board holds information about a whole 5x5x5 chessboard
struct FullBoard
{
	// space : holds every Field in the board
	std::vector<std::vector<std::vector<Field> > > space;
	FullBoard();
	// at : returns a Field at a given Coord of the board
	Field& at(const Coord& place);
	
	friend std::ostream& operator<<(std::ostream& os, const Model::FullBoard& board);
	friend std::istream& operator>>(std::istream& is, Model::FullBoard& board);
};

}
#endif
