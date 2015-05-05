#include "gameevent.h"
#include "move.h"

namespace Model
{

PointerToGameEvent GameEvent::generateMove(const std::string& moveDesc, Game* theGame)
{
    try {
	return generateMoveFromString(moveDesc, theGame);
    } catch (...) {
	std::string errorMessage("Bad move data in GameEvent::generateMove: ");
	throw std::invalid_argument(errorMessage + moveDesc);
    }
}

PointerToGameEvent GameEvent::generateMoveFromString(const std::string& moveDesc, Game* theGame)
{
    std::string fromString { moveDesc.substr(0, 3) };
    std::string toString { moveDesc.substr(4, 3) };
    Position from {fromString};
    Position to {toString};
    PointerToPiece promoteTo = nullptr;
    if (isPromotion(from, to, theGame))
    {
	std::string pieceDesc =
	    (theGame->getHistory()->getNextPlayer() == Player::White) ?
	    "wQ" : "bQ";
	pieceDesc.append(toString);
	promoteTo = Piece::generatePiece(pieceDesc, theGame->getBoard());
    }
    PointerToGameEvent theMove { new Move {theGame, from, to, promoteTo} };
    return theMove;
}

bool GameEvent::isPromotion(Position& from, Position& to, Game* theGame)
{
    // if it's a pawn
    // at entering the last line
    // return true
    return false; // TODO
}


void GameEvent::setGame(Game* theGame)
{
    game = theGame;
}



GameEvent::GameEvent(Game* theGame) : game{theGame}
{
}

GameEvent::~GameEvent()
{
}

int GameEvent::getMoveNumber() const
{
    return moveNumber;
}

Player GameEvent::getPlayer() const
{
    return player;
}


void GameEvent::setPlayerAndMoveNumberBasedOnPreviousGameEvent()
{
    Model::Player previousPlayer = game->getHistory()->getPlayerForLastEvent();
    if (Player::White == previousPlayer)
    {
	player = Player::Black;
    } else if (Player::Black == previousPlayer)
    {
	player = Player::White;
    } else {
	player = Player::Nobody;
    }
    
    moveNumber = game->getHistory()->getMoveNumberForLastEvent();
    if (player == Player::White)
    {
	++moveNumber;
    }    
}

std::ostream& operator<<(std::ostream& outputStream, const Model::GameEvent& gameEvent)
{
    outputStream << gameEvent.getNotation();
    return outputStream;
}


}