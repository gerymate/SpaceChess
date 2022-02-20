// (C) Máté Gergely - gerymate@gmail.com
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<vector>
#include "fullboard.h"
#include "field.h"
#include "player.h"

namespace Model {
    
struct GameState
{
	FullBoard board;
	Player nextPlayer;
	GameState();
	
	friend std::ostream& operator<<(std::ostream& os, const Model::GameState& gs);
	friend std::istream& operator>>(std::istream& is, Model::GameState& gs);
};

}
#endif
