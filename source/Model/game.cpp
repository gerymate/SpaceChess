#include "game.h"

namespace Model
{

const std::string defaultBoard = 
    " bREa5 bNEb5 bKEc5 bNEd5 bREe5"
    " bPEa4 bPEb4 bPEc4 bPEd4 bPEe4"

    " bBDa5 bUDb5 bQDc5 bBDd5 bUDe5"
    " bPDa4 bPDb4 bPDc4 bPDd4 bPDe4"

    " wPBa2 wPBb2 wPBc2 wPBd2 wPBe2"
    " wBBa1 wUBb1 wQBc1 wBBd1 wUBe1"
    
    " wPAa2 wPAb2 wPAc2 wPAd2 wPAe2"
    " wRAa1 wNAb1 wKAc1 wNAd1 wRAe1";
    
Game::Game() : board{ defaultBoard }, history{ &board }, judge{ &board, &history }
{

}


GameState Game::getGameState()
{
    GameState currentState;
    currentState.board = board.getFullBoard();
    currentState.nextPlayer = history.getNextPlayer();
    return currentState;
}

PointerToPositionList Game::getCurrentlyPossibleMovesFrom(Position& from)
{
    return judge.getCurrentlyPossibleMovesFrom(from);
}

PointerToPositionList Game::getPossibleMovesFrom(Position& from)
{
    return judge.getPossibleMovesFrom(from);
}

std::string Game::move(Position& from, Position& to, Figure promoteTo)
{
    std::string result {"Invalid move"};
    
    if (judge.isValidMove(from, to))
    {
	PointerToGameEvent aMove { new Move { from, to } };
	history.addEvent(aMove);
	history.actualize();
	
	result = aMove->getNotation();
    }
    
    return result;
}

std::string Game::move(Position& from, Position& to)
{
    return move(from, to, Figure::Queen);
}

    
    
}
