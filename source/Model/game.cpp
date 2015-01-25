#include "game.h"

using namespace Model;

Game::Game(const GameState& gs = GameState()) : state(gs)
{
}

void Game::setGameState(const GameState& gs)
{
    state = gs;
}

const GameState& Game::getGameState() const
{
	return state;
}

bool Game::touch(const Coord& place)
{
	if (state.phase == 0) {
		if (state.board.at(place).owner != state.nextPlayer) {
			return false;
		}
		state.touched = place;
		state.phase = 1;
	} else if (state.phase == 1) {
		move(state.touched, place);
		if (state.nextPlayer == 1) ++(state.nextPlayer);
		else if (state.nextPlayer == 2) --(state.nextPlayer);
		state.touched = place;
		state.phase = 0;
	}
	return true;
}

bool Game::move(const Coord& from, const Coord& to)
{
	state.board.at(to).owner = state.board.at(from).owner;
	state.board.at(to).figure = state.board.at(from).figure;
	state.board.at(from).owner = 0;
	state.board.at(from).figure = 0;	
	return true;
}
