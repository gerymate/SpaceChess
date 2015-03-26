#ifndef GAMEV1_H
#define GAMEV1_H

#include "gamestate.h"
#include "coord.h"

namespace Model {
//	A Game is a full abstraction of a single SpaceChess game

class GameV1
{
	GameState state;
	bool move(const Coord& from, const Coord& to);

public:
	GameV1() {};
	GameV1(const GameState& gs);
	void setGameState(const GameState& gs);
	const GameState& getGameState() const;
	bool touch(const Coord& place);
};

}

#endif
