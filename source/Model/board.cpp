// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "board.h"
#include <sstream>

namespace Model
{

Board::Board(std::string boardDesc)
{
    std::stringstream stringStream;
    stringStream << boardDesc;
    stringStream >> (*this);
}

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

PointerToPiece Board::getPiece(const Position& atField) const
{
    PointerToPiece piece = nullptr;
    auto pi = piecesOnBoard.find(atField);
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

FullBoard Board::getFullBoard() const
{
    FullBoard fb;
    for(int y = 0; y != 5; ++y) 
    {
	for(int x = 0; x != 5; ++x) 
	{
	    for(int z = 0; z != 5; ++z) 
	    {
		if(auto piece = getPiece({y + 1, x + 1, z + 1}))
		{
		    fb.space.at(y).at(x).at(z) = Field{piece->getPlayer(), piece->getFigure(), Position(y+1, x+1, z+1)};
		}
	    }
	}
    }
    return fb;
}

Position Board::find(Player player, Figure figure)
{
    Position place {Position::Invalid};
    for (auto pp : piecesOnBoard)
    {
	PointerToPiece piece = pp.second;
	if ( piece->getPlayer() == player && piece->getFigure() == figure )
	{
	    place = pp.first;
	    break;
	}
    }
    return place;
}

PointerToPointerToPieceList Board::getAllPiecesFor(Player player)
{
    PointerToPointerToPieceList allPiecesForPlayer = std::make_shared<PointerToPieceList>();
    for (auto pp : piecesOnBoard)
    {
	PointerToPiece piece {pp.second}; 
	if (piece->getPlayer() == player)
	{
	    allPiecesForPlayer->push_back(piece);
	}
    }
    return allPiecesForPlayer;
}

Board::~Board()
{

}


std::ostream& operator<<(std::ostream& outputStream, const Model::Board& board)
{
    for (auto piece : board.piecesOnBoard)
    {
	outputStream << piece.second << piece.first << " ";
    }
    
    return outputStream;
    
}


std::istream& operator>>(std::istream& inputStream, Model::Board& board)
{
    std::string temp;
    while (inputStream >> temp)
    {
	PointerToPiece piece = Piece::generatePiece(temp, &board);
	board.addPiece(piece->getPosition(), piece); 	// error checking?
    }
    
    return inputStream;
    
}

}