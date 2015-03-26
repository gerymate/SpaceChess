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

PointerToPiece Piece::generatePiece(std::string pieceDesc)
{
    PointerToPiece piece;
    try {
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
	    default: throw std::invalid_argument("Bad piece data, cannot generate piece.");	
	}

	char playerDesc {pieceDesc.at(0)};
	if (playerDesc != 'w' && playerDesc != 'b')
	{
	    throw std::exception{};
	}
	piece->player = (playerDesc == 'w') ? Player::White : Player::Black;
	
	std::string positionDesc {pieceDesc, 2, 3};
	piece->setPosition(Position{positionDesc});
	
    } catch (std::exception& e) {
	throw std::invalid_argument("Bad piece data, cannot generate piece.");	
    }
    return piece;
}


}