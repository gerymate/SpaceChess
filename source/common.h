#ifndef COMMON_H
#define COMMON_H

#include <memory>
#include <set>
#include <list>
#include <stdexcept>
#include <queue>
#include <string>

namespace Model
{
    class Position;
    using PositionList = std::list<Position>;
    using PointerToPositionList = std::shared_ptr<PositionList>;

    class Game;
    class History;
    class Judge;

    class GameEvent;
    class Move;
    using PointerToGameEvent = std::shared_ptr<GameEvent>;
    class Piece;
    using PointerToPiece = std::shared_ptr<Piece>;
    class Board;
    using PointerToBoard = std::shared_ptr<Board>;    
}

class Event;
using PointerToEvent = std::shared_ptr<Event>;
using EventQueue = std::queue<PointerToEvent>;


#endif // COMMON_H
