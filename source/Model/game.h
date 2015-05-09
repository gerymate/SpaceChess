#ifndef GAME_H
#define GAME_H

// old
#include "gamestate.h"

// new
#include "common.h"
#include "board.h"
#include "history.h"
#include "judge.h"
#include "figure.h"

namespace Model {
//	A Game is a full abstraction of a single SpaceChess game

class Game
{
    Board board;
    History* history;
    Judge* judge;
    bool ended{false};

public:
	Game();
	~Game();
	GameState getGameState();
	PointerToPositionList getCurrentlyPossibleMovesFrom(Position& from);
	Player getNextPlayer();
	std::string move(Position& from, Position& to);
	std::string move(Position& from, Position& to, Figure promoteTo);
	std::string stepForward();
	std::string stepBackward();
	
	Board* getBoard();
	History* getHistory();
	Judge* getJudge();

    	friend std::ostream& operator<<(std::ostream& outputStream, const Model::Game& game);
    	friend std::istream& operator>>(std::istream& inputStream, Model::Game& game);
};

}

#endif
