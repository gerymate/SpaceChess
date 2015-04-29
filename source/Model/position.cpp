#include "position.h"
#include <string>
#include <sstream>

namespace Model 
{

Position::Position(int theLevel, int theFile, int theRank) :
	level(theLevel), file(theFile), rank(theRank)
{

}

Position::Position(const Coord& coord) :
	level{coord.y + 1}, file{coord.x + 1}, rank{coord.z + 1}
{

}


bool Position::isValid() const
{
    return 1 <= level && level <= 5
	&& 1 <= file && file <= 5
	&& 1 <= rank && rank <= 5;
}


bool operator< (const Position& lhs, const Position& rhs)
{
    if (lhs.level < rhs.level) return true;
    if (lhs.level > rhs.level) return false;
    // levels are equal
    if (lhs.file < rhs.file) return true;
    if (lhs.file > rhs.file) return false;
    // levels and files are equal
    if (lhs.rank < rhs.rank) return true;
    return false;
}

std::ostream& operator<<(std::ostream& outputStream, const Model::Position& position)
{
    if (position.isValid())
    {
	const std::string levelNotation {"ABCDE"};
	const std::string fileNotation {"abcde"};
	const std::string rankNotation {"12345"};
	
	outputStream 
	    << levelNotation.at(position.getLevel()-1) 
	    << fileNotation.at(position.getFile()-1) 
	    << rankNotation.at(position.getRank()-1);
    } else {
	outputStream << "???";
    }
    return outputStream;
}

std::string Position::getNotation()
{
    std::stringstream notation;
    notation << *this;
    return notation.str();
}

Position::Position(const std::string& positionDesc)
{
    try {
	const std::string levelNotation {"ABCDE"};
	const std::string fileNotation {"abcde"};
	const std::string rankNotation {"12345"};
	
	level = 1 + levelNotation.find(positionDesc.at(0));
	file = 1 + fileNotation.find(positionDesc.at(1));
	rank = 1 + rankNotation.find(positionDesc.at(2));

	if( ! this->isValid() ) 
	{
	    throw std::exception{};
	}
	
    } catch(std::exception& e) {
	throw std::invalid_argument("Bad position data, cannot create position");
    }
}




}