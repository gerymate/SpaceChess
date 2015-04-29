#ifndef COMMON_H
#define COMMON_H

#include <memory>
#include <set>
#include <list>
#include <stdexcept>

namespace Model
{
    class GameEvent;
    using PointerToGameEvent = std::shared_ptr<GameEvent>;
    class Piece;
    using PointerToPiece = std::shared_ptr<Piece>;
    class Board;
    using PointerToBoard = std::shared_ptr<Board>;
    
    class Position;
    using PositionList = std::list<Position>;
    struct Coord;
}


#endif // COMMON_H
