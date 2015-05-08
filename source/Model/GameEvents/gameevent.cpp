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

PointerToGameEvent GameEvent::generateMove(const Position& from, const Position& to, Game* theGame)
{
    PointerToPiece promoteTo = nullptr;
    if (isPromotion(from, to, theGame))
    {
	std::string pieceDesc = 
	    (theGame->getNextPlayer() == Player::White) ?
	    "wQ" : "bQ";
	pieceDesc.append(to.getNotation());
	promoteTo = Piece::generatePiece(pieceDesc, theGame->getBoard());
    }
    PointerToGameEvent theMove { new Move {theGame, from, to, promoteTo} };
    return theMove;
}

PointerToGameEvent GameEvent::generateMoveFromString(const std::string& moveDesc, Game* theGame)
{
    const std::string fromString { moveDesc.substr(0, 3) };
    const std::string toString { moveDesc.substr(4, 3) };
    const Position from {fromString};
    const Position to {toString};
    return generateMove(from, to, theGame);
}

bool GameEvent::isPromotion(const Position& from, const Position& to, Game* theGame)
{
    bool promotion = false;
    PointerToPiece piece = theGame->getBoard()->getPiece(from);
    if (piece && piece->getFigure() == Figure::Pawn)
    {
	const int level = to.getLevel();
	const int rank = to.getRank();
	if (piece->getPlayer() == Player::White)
	{
	    if (rank == 5 && (level == 4 || level == 5)) promotion = true;
	} else if (piece->getPlayer() == Player::Black) {
	    if (rank == 1 && (level == 1 || level == 2)) promotion = true;
	}
    }
    return promotion;
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