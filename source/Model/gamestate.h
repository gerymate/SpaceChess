#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<vector>
#include "board.h"
#include "field.h"
#include "coord.h"
#include "player.h"
#include "phase.h"

namespace Model {
    
struct GameState
{
	Board board;
	Player nextPlayer;
	Phase phase;
	Coord touched; 
	GameState();
	
	friend std::ostream& operator<<(std::ostream& os, const Model::GameState& gs);
	friend std::istream& operator>>(std::istream& is, Model::GameState& gs);
};

}
#endif
