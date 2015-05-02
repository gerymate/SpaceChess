#ifndef GAME_H
#define GAME_H

// old
#include "gamestate.h"

// new
#include "board.h"
#include "history.h"
#include "judge.h"
#include <string>
#include <list>
#include "common.h"
#include "figure.h"
#include "move.h"

namespace Model {
//	A Game is a full abstraction of a single SpaceChess game

class Game
{
    Board board;
    History history;
    Judge judge;

public:
	Game();
//	Game(const GameState& gs);
//	void setGameState(const GameState& gs);
	GameState getGameState();
	PointerToPositionList getPossibleMovesFrom(Position& from);
	std::string move(Position& from, Position& to);
	std::string move(Position& from, Position& to, Figure promoteTo);
};

}

#endif
