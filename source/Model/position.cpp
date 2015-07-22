// (C) Máté Gergely - gerymate@gmail.com
#include "position.h"
#include <string>
#include <sstream>

namespace Model 
{

    
Position::Position(int theLevel, int theFile, int theRank) : // (y, x, z)!
	level(theLevel), file(theFile), rank(theRank)
{

}

const Position Position::Invalid {-1, -1, -1};

bool Position::isValid() const
{
    return 0 <= level && level <= 4
	&& 0 <= file && file <= 4
	&& 0 <= rank && rank <= 4;
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
	    << levelNotation.at(position.getLevel()) 
	    << fileNotation.at(position.getFile()) 
	    << rankNotation.at(position.getRank());
    } else {
	outputStream << "???";
    }
    return outputStream;
}

std::string Position::getNotation() const
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
	
	level = levelNotation.find(positionDesc.at(0));
	file = fileNotation.find(positionDesc.at(1));
	rank = rankNotation.find(positionDesc.at(2));

	if( ! this->isValid() ) 
	{
	    throw std::exception{};
	}
	
    } catch(std::exception& e) {
	throw std::invalid_argument("Bad position data, cannot create position");
    }
}




}