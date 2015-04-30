#include "game.h"

namespace Model
{

const std::string defaultBoard = 
    " bREa5 bNEb5 bKEc5 bNEd5 bREe5"
    " bPEa4 bPEb4 bPEc4 bPEd4 bPEe4"

    " bBDa5 bUDb5 bQDc5 bUDd5 bBDe5"
    " bPDa4 bPDb4 bPDc4 bPDd4 bPDe4"

    " wPBa2 wPBb2 wPBc2 wPBd2 wPBe2"
    " wBBa1 wUBb1 wQBc1 wUBd1 wBBe1"
    
    " wPAa2 wPAb2 wPAc2 wPAd2 wPAe2"
    " wRAa1 wNAb1 wKAc1 wNAd1 wRAe1";
    
Game::Game() : board{defaultBoard}, history(&board)
{

}


GameState Game::getGameState()
{
    GameState currentState;
    currentState.board = board.getFullBoard();
    currentState.nextPlayer = history.getNextPlayer();
    return currentState;
}


bool Game::touch(const Coord& place)
{
    return false;
}

std::string Game::move(Position& from, Position& to, Figure promoteTo)
{
    std::string result;
    
    // get info: is it a valid move???
    
    PointerToGameEvent aMove { new Move { from, to } };
    history.addEvent(aMove);
    history.actualize();
    
    return std::string{ "OK" };
}

std::string Game::move(Position& from, Position& to)
{
    return move(from, to, Figure::Queen);
}

    
    
}
