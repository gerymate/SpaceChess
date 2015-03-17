#ifndef GAME_H
#define GAME_H

#include "gamestate.h"
#include "coord.h"

namespace Model {
//	A Game is a full abstraction of a single SpaceChess game

class Game
{
	GameState state;
	bool move(const Coord& from, const Coord& to);

public:
	Game() {};
	Game(const GameState& gs);
	void setGameState(const GameState& gs);
	const GameState& getGameState() const;
	bool touch(const Coord& place);
};

}

#endif
