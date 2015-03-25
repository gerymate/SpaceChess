#ifndef POSITION_H
#define POSITION_H

#include <iostream>

namespace Model {

class Position
{
    int level, file, rank;
public:
    Position(int theLevel = 0, int theFile = 0, int theRank = 0);
    const int getLevel() const { return level; }
    const int getFile() const { return file; }
    const int getRank() const { return rank; }
    bool isValid() const;
    friend bool operator< (const Position& lhs, const Position& rhs);
    bool operator==(const Position& rhs) const { return level==rhs.level && file==rhs.file && rank==rhs.rank; }
};

std::ostream& operator<<(std::ostream& outputStream, const Model::Position& position);

}

#endif // POSITION_H
