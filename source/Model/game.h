#ifndef GAME_H
#define GAME_H

// old
#include "gamestate.h"
#include "coord.h"

// new
#include "board.h"
#include "history.h"
#include <string>

namespace Model {
//	A Game is a full abstraction of a single SpaceChess game

class Game
{
    Board board;
    History history;

public:
	Game();
//	Game(const GameState& gs);
//	void setGameState(const GameState& gs);
	GameState getGameState();
	bool touch(const Coord& place);
};

}

#endif
