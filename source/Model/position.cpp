#include "position.h"

namespace Model 
{

Position::Position(int theLevel, int theFile, int theRank) :
	level(theLevel), file(theFile), rank(theRank)
{

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



}