#include "gamestate.h"

GameState::GameState() 
	: board(Board())
	, nextPlayer(1)
	, phase(0)
	, touched(Coord())
{
}

std::ostream& operator<<(std::ostream& os, const GameState& gs)
{	
	os << gs.board;
    return os;
}

std::istream& operator>>(std::istream& is, GameState& gs) {
	is >> gs.board;
	return is;
}
