// (C) Máté Gergely - gerymate@gmail.com
#include "gamestate.h"

namespace Model {
    
GameState::GameState() 
	: board(FullBoard())
	, nextPlayer(Player::White)
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