#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<vector>
#include "board.h"
#include "field.h"
#include "coord.h"

//	A GameState object describes a single situation that could emerge in a Game

struct GameState
{
	// board : full description of the current state of the chessboard
	Board board;
	// nextPlayer: (0 : game over; 1 : white; 2 : black)
	int nextPlayer;
	// phase : describes what's happening (0 : ready to move; 1 : touched sg; 2 : ...)
	int phase;
	// touched : which Field has been touched?
	Coord touched; 
	GameState();
	
	friend std::ostream& operator<<(std::ostream& os, const GameState& gs);
	friend std::istream& operator>>(std::istream& is, GameState& gs);
};


#endif
