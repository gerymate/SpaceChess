// (C) Máté Gergely - gerymate@gmail.com
#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include "common.h"

namespace Model {

class Position
{
    int level, file, rank;
public:
    Position(int theLevel = -1, int theFile = -1, int theRank = -1);
    Position(const std::string& positionDesc); 
    const int getLevel() const { return level; }
    const int getFile() const { return file; }
    const int getRank() const { return rank; }
    bool isValid() const;
    friend bool operator< (const Position& lhs, const Position& rhs);
    bool operator==(const Position& rhs) const { return level==rhs.level && file==rhs.file && rank==rhs.rank; }
    bool operator!=(const Position& rhs) const { return !operator==(rhs); }
    
    static const Position Invalid;
    
    Position over() const 	{ return over(*this); }
    Position under() const 	{ return under(*this); }
    Position right() const 	{ return right(*this); }
    Position left() const 	{ return left(*this); }
    Position farther() const 	{ return farther(*this); }
    Position closer() const 	{ return closer(*this); }

    static Position over(const Position& p) 	{ return Position{p.level+1, p.file, p.rank}; }
    static Position under(const Position& p) 	{ return Position{p.level-1, p.file, p.rank}; }
    static Position right(const Position& p) 	{ return Position{p.level, p.file+1, p.rank}; }
    static Position left(const Position& p) 	{ return Position{p.level, p.file-1, p.rank}; }
    static Position farther(const Position& p) 	{ return Position{p.level, p.file, p.rank+1}; }
    static Position closer(const Position& p) 	{ return Position{p.level, p.file, p.rank-1}; }
    
    std::string getNotation() const;
};

std::ostream& operator<<(std::ostream& outputStream, const Model::Position& position);

}

#endif // POSITION_H
