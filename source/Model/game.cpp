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
    bool validTouch = false;
    if (! place.isOnTheBoard())
    { 
	// this is not a real touch :-)
    } else if (state.phase == Phase::Selection) {
	    if (state.board.at(place).owner == state.nextPlayer) 
	    {
		state.touched = place;
		state.phase = Phase::Move;
		validTouch = true;
	    }
    } else if (state.phase == Phase::Move) {
	    if (move(state.touched, place))
	    {
		if (state.nextPlayer == Player::Black) state.nextPlayer = Player::White;
		else if (state.nextPlayer == Player::White) state.nextPlayer = Player::Black;
		state.touched = place;
		state.phase = Phase::Selection;
		validTouch = true;
	    }
    }
    return validTouch;
}

bool Game::move(const Coord& from, const Coord& to)
{
    bool validMove = false;
    if (from != to)
    {
	state.board.at(to).owner = state.board.at(from).owner;
	state.board.at(to).figure = state.board.at(from).figure;
	state.board.at(from).owner = Player::Nobody;
	state.board.at(from).figure = Figure::None;
	validMove = true;
    }
    return validMove;
}
