#include "board.h"

namespace Model
{

bool Board::addPiece(const Position& atField, PointerToPiece piece)
{
    bool success = false;
    if (piecesOnBoard.find(atField) == end(piecesOnBoard))
    {
	piecesOnBoard[atField] = piece;
	piece->setPosition(atField);
	success = true;
    }
    return success;
}

bool Board::removePiece(const Position& atField)
{
    bool success = false;
    auto pi = piecesOnBoard.find(atField);    
    if (pi != end(piecesOnBoard))
    {
	piecesOnBoard.erase(pi);
	success = true;
    }
    return success;    
}

PointerToPiece Board::getPiece(const Position& atField)
{
    auto pi = piecesOnBoard.find(atField);
    PointerToPiece piece = nullptr;
    if (pi != end(piecesOnBoard))
    {
	piece = pi->second;
    }
    return piece;
}

bool Board::isOccupied(const Position& atField)
{
    return !(nullptr == getPiece(atField));
}

FullBoard Board::getFullBoard()
{
    FullBoard fb;
    for(int y = 0; y != 5; ++y) 
    {
	for(int x = 0; x != 5; ++x) 
	{
	    for(int z = 0; z != 5; ++z) 
	    {
		if(auto piece = getPiece({y, x, z}))
		{
		    fb.space.at(y).at(x).at(z) = Field(piece->getPlayer(), piece->getFigure(), Coord(y, x, z));
		}
	    }
	}
    }
    return fb;
}

    
    
    
}