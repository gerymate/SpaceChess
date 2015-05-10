#include "piece.h"

#include "common.h"
#include "board.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "unicorn.h"
#include "pawn.h"

namespace Model
{

Piece::~Piece()
{

}

PointerToPiece Piece::generatePiece(const std::string& pieceDesc, Board* theBoard)
{
    try {
	return generatePieceFromString(pieceDesc, theBoard);
    } catch (...) {
	std::string errorMessage("Bad piece data in Piece::generatePiece: ");
	throw std::invalid_argument(errorMessage + pieceDesc);
    }
}

PointerToPiece Piece::generatePieceFromString(std::string pieceDesc, Board* theBoard)
{
    PointerToPiece piece;

    char figureDesc {pieceDesc.at(1)};
    switch (figureDesc)
    {
	case 'K': piece = std::make_shared<King>(); break;
	case 'Q': piece = std::make_shared<Queen>(); break;
	case 'R': piece = std::make_shared<Rook>(); break;
	case 'B': piece = std::make_shared<Bishop>(); break;
	case 'N': piece = std::make_shared<Knight>(); break;
	case 'U': piece = std::make_shared<Unicorn>(); break;
	case 'P': piece = std::make_shared<Pawn>(); break;
	default: throw -1;
    }

    char playerDesc {pieceDesc.at(0)};
    if (playerDesc != 'w' && playerDesc != 'b')
    {
	throw -2;
    }
    piece->player = (playerDesc == 'w') ? Player::White : Player::Black;
    
    std::string positionDesc {pieceDesc, 2, 3};
    piece->setPosition(Position{positionDesc});

    piece->board = theBoard;

    return piece;
}

PointerToPositionList Piece::getPossibleMoves()
{
    PointerToPositionList basicPossibilities { new PositionList {{3, 3, 3}, {3, 2, 3}, {3, 4, 3}} };
    
    basicPossibilities->remove_if([](Position p){ return ! (p.isValid()); }); // remove offboard fields

    return basicPossibilities;
}

PointerToPositionList Piece::getPossibleTakes()
{
    // except for the Pawn, if a piece can move to a position, it can take the figure there
    return getPossibleMoves();
}

void Piece::filterForOnBoard(PointerToPositionList targets)
{
    auto current = targets->begin();
    auto last = targets->end();
    while (current != last)
    {
	if ( !(*current).isValid() )
	{
	    current = targets->erase(current);
	} else {
	    ++current;
	}
    }    
}

void Piece::filterForMove(PointerToPositionList targets)
{
    auto current = targets->begin();
    auto last = targets->end();
    while (current != last)
    {
	if (! canMoveTo(*current))
	{
	    current = targets->erase(current);
	} else {
	    ++current;
	}
    }    
}

bool Piece::canMoveTo(const Position& position)
{
    return (position.isValid() && !board->isOccupied(position));
}

void Piece::filterForTake(PointerToPositionList targets)
{
    auto current = targets->begin();
    auto last = targets->end();
    while (current != last)
    {
	if (! canTakeAt(*current))
	{
	    current = targets->erase(current);
	} else {
	    ++current;
	}
    }    
}

bool Piece::canTakeAt(const Position& position)
{
    return (position.isValid() && 
	    board->isOccupied(position) && 
	    board->getPiece(position)->getPlayer() != player);
}

void Piece::filterForMoveOrTake(PointerToPositionList targets)
{
    auto current = targets->begin();
    auto last = targets->end();
    while (current != last)
    {
	if (! canMoveToOrTakeAt(*current))
	{
	    current = targets->erase(current);
	} else {
	    ++current;
	}
    }    
}

bool Piece::canMoveToOrTakeAt(const Position& position)
{
    return (position.isValid() &&
	    (!board->isOccupied(position) || board->getPiece(position)->getPlayer() != player));
}

PointerToPositionList Piece::moveOrTakeStraightFrom(const Position& position)
{
    if (!position.isValid())
    {
	return nullptr;
    }

    PointerToPositionList possibleMoves = std::make_shared<PositionList>();

    DirectionFunctionList directions {
	[] (Position p) { return Position::over(p); },
	[] (Position p) { return Position::under(p); },
	[] (Position p) { return Position::right(p); },
	[] (Position p) { return Position::left(p); },
	[] (Position p) { return Position::farther(p); },
	[] (Position p) { return Position::closer(p); }
    };
    
    addPositionsFromSourceInManyDirections(possibleMoves, position, directions);    
    
    return possibleMoves;  
}

PointerToPositionList Piece::moveOrTakePlaneDiagonallyFrom(const Position& position)
{
    if (!position.isValid())
    {
	return nullptr;
    }

    PointerToPositionList possibleMoves = std::make_shared<PositionList>();

    DirectionFunctionList directions {
    // plane with normal y
	[] (Position p) { return Position::farther(Position::right(p)); },
	[] (Position p) { return Position::closer(Position::right(p)); },
	[] (Position p) { return Position::farther(Position::left(p)); },
	[] (Position p) { return Position::closer(Position::left(p)); },
    // plane with normal x
	[] (Position p) { return Position::farther(Position::over(p)); },
	[] (Position p) { return Position::closer(Position::over(p)); },
	[] (Position p) { return Position::farther(Position::under(p)); },
	[] (Position p) { return Position::closer(Position::under(p)); },    
    // plane with normal z
	[] (Position p) { return Position::over(Position::right(p)); },
	[] (Position p) { return Position::under(Position::right(p)); },
	[] (Position p) { return Position::over(Position::left(p)); },
	[] (Position p) { return Position::under(Position::left(p)); }
    };
    
    addPositionsFromSourceInManyDirections(possibleMoves, position, directions);    
    
    return possibleMoves;
}

PointerToPositionList Piece::moveOrTakeTrueDiagonallyFrom(const Position& position)
{
    if (!position.isValid())
    {
	return nullptr;
    }

    PointerToPositionList possibleMoves = std::make_shared<PositionList>();

    DirectionFunctionList directions {
    // up
	[] (Position p) { return Position::over(Position::farther(Position::right(p))); },
	[] (Position p) { return Position::over(Position::closer(Position::right(p))); },
	[] (Position p) { return Position::over(Position::farther(Position::left(p))); },
	[] (Position p) { return Position::over(Position::closer(Position::left(p))); },
    // down
	[] (Position p) { return Position::under(Position::farther(Position::right(p))); },
	[] (Position p) { return Position::under(Position::closer(Position::right(p))); },
	[] (Position p) { return Position::under(Position::farther(Position::left(p))); },
	[] (Position p) { return Position::under(Position::closer(Position::left(p))); },
    };
    
    addPositionsFromSourceInManyDirections(possibleMoves, position, directions);    
    
    return possibleMoves;
}

void Piece::addPositionsFromSourceInManyDirections(PointerToPositionList positionList, 
						   const Position& sourcePosition, 
						   DirectionFunctionList directions)
{
    for (DirectionFunction dirFunc : directions)
    {
	addPositionsFromSourceInDirection(positionList, sourcePosition, dirFunc);
    }
}

void Piece::addPositionsFromSourceInDirection(PointerToPositionList positionList, 
					      const Position& sourcePosition, 
					      DirectionFunction directionFunction)
{
    Position current = directionFunction(sourcePosition);
    while (canMoveToOrTakeAt(current))
    {
	positionList->push_back(current);
	if(canTakeAt(current)) break;
	current = directionFunction(current);
    }
}



}