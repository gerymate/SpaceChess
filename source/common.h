#ifndef COMMON_H
#define COMMON_H

#include <memory>
#include <set>
#include <list>
#include <stdexcept>
#include <queue>

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

class Event;
using PointerToEvent = std::shared_ptr<Event>;
using EventQueue = std::queue<PointerToEvent>;


#endif // COMMON_H
