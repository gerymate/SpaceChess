#ifndef COMMON_H
#define COMMON_H

#include <memory>

namespace Model
{
    class GameEvent;
    using PointerToGameEvent = std::shared_ptr<GameEvent>;
    class Piece;
    using PointerToPiece = std::shared_ptr<Piece>;
    class Board;
    using PointerToBoard = std::shared_ptr<Board>;
    
    class Position;
    struct Coord;
}


#endif // COMMON_H
