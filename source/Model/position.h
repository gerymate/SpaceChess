#ifndef POSITION_H
#define POSITION_H

namespace Model {

class Position
{
    int level, file, rank;
public:
    Position(int theLevel = 0, int theFile = 0, int theRank = 0);
    const int getLevel() const { return level; }
    const int getFile() const { return file; }
    const int getRank() const { return rank; }
};

}

#endif // POSITION_H
