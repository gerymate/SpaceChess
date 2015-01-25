#include "gamestate.h"

namespace Model {
    
GameState::GameState() 
	: board(Board())
	, nextPlayer(1)
	, phase(0)
	, touched(Coord())
{
}

std::ostream& operator<<(std::ostream& os, const Model::GameState& gs)
{	
	os << gs.board;
    return os;
}

std::istream& operator>>(std::istream& is, Model::GameState& gs) {
	is >> gs.board;
	return is;
}

}