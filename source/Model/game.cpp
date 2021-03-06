// (C) Máté Gergely - gerymate@gmail.com
#include "game.h"
#include "board.h"

#include "gameevent.h"

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
    
Game::Game() : board{ new Board{ defaultBoard } }
{
    history = new History {this};
    judge = new Judge {this};
}

Game::~Game()
{
    delete judge;
    delete history;
    delete board;
}

std::string Game::move(Position& from, Position& to)
{
    return move(from, to, Figure::Queen);
}

std::string Game::move(Position& from, Position& to, Figure promoteTo)
{
    std::string result {"Invalid move"};
    
    if (judge->isValidMove(from, to))
    {
	std::string moveDesc { from.getNotation() };
	moveDesc.append( " " );
	moveDesc.append( to.getNotation() );
	PointerToGameEvent aMove { GameEvent::generateMove(moveDesc, this) };
	history->addEvent(aMove);
	history->actualize();
	
	result = aMove->getNotation();
	
	const Player nextPlayer {getNextPlayer()};
	const bool isInCheck {judge->isInCheck(nextPlayer)};
	const bool canMove {judge->canMove(nextPlayer)};
	
	if (!canMove)
	{
	    ended = true;
	    if (isInCheck)
	    {
		result.append("   * Checkmate *");
	    } else {
		result.append("   * Draw *");
	    };
	} else if (isInCheck) {
	    result.append("   * Check *");	    
	}	
    }
    
    return result;
}

std::string Game::stepBackward()
{
    return history->stepBack() ? "" : "There are no previous moves."; 
}

std::string Game::stepForward()
{
    return history->stepForward() ? "" : "There are no more moves."; 
}

GameState Game::getGameState() const
{
    GameState currentState;
    currentState.board = board->getFullBoard();
    currentState.nextPlayer = getNextPlayer();
    return currentState;
}

PointerToPositionList Game::getCurrentlyPossibleMovesFrom(Position& from) const
{
    return judge->getCurrentlyPossibleMovesFrom(from);
}

Player Game::getNextPlayer() const
{
    return ended ? (Player::Nobody) : (history->getNextPlayer());
}

Board* Game::getBoard() const
{
    return board;
}

IBoardInfo* Game::getBoardInfo() const
{
    return board;
}

History* Game::getHistory() const
{
    return history;
}

Judge* Game::getJudge() const
{
    return judge;
}

std::ostream& operator<<(std::ostream& outputStream, const Model::Game& game)
{
    outputStream << *(game.history);
    return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Model::Game& game)
{
    inputStream >> *(game.history);
    return inputStream;
}


}
