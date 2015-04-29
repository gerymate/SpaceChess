#include "piece.h"

#include "common.h"
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



}