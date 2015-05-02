#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <string>
#include "common.h"

namespace Model {

class Position
{
    int level, file, rank;
public:
    Position(int theLevel = 0, int theFile = 0, int theRank = 0);
    Position(const std::string& positionDesc); 
    const int getLevel() const { return level; }
    const int getFile() const { return file; }
    const int getRank() const { return rank; }
    bool isValid() const;
    friend bool operator< (const Position& lhs, const Position& rhs);
    bool operator==(const Position& rhs) const { return level==rhs.level && file==rhs.file && rank==rhs.rank; }
    bool operator!=(const Position& rhs) const { return !operator==(rhs); }
    
    static const Position Invalid;
    
    Position over() const 	{ return Position{level + 1, file, rank}; }
    Position under() const 	{ return Position{level - 1, file, rank}; }
    Position right() const 	{ return Position{level, file + 1, rank}; }
    Position left() const 	{ return Position{level, file - 1, rank}; }
    Position farther() const 	{ return Position{level, file, rank + 1}; }
    Position closer() const 	{ return Position{level, file, rank - 1}; }
    
    std::string getNotation() const;
};

std::ostream& operator<<(std::ostream& outputStream, const Model::Position& position);

}

#endif // POSITION_H
