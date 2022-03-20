// (C) Máté Gergely - gerymate@gmail.com
#include "pawn.h"

namespace Model
{
    
PointerToPositionList Pawn::getPossibleMoves()
{
    PointerToPositionList movePossibilities {getMovePossibilities()};
    PointerToPositionList takePossibilities {getTakePossibilities()};
    
    filterForMove(movePossibilities);
    filterForTake(takePossibilities);
    
    movePossibilities->splice(movePossibilities->begin(), *takePossibilities);

    return movePossibilities;    
}

PointerToPositionList Pawn::getPossibleTakes()
{
    PointerToPositionList takePossibilities {getTakePossibilities()};
    filterForOnBoard(takePossibilities);
    return takePossibilities;
}


PointerToPositionList Pawn::getMovePossibilities()
{
    PointerToPositionList movePossibilities;
    if (player == Player::White)
    {
	movePossibilities.reset( new PositionList { position.farther(), position.over() } );
    } else { // it's Black!
	movePossibilities.reset( new PositionList { position.closer(), position.under() } );
    }
    
    return movePossibilities;
}

PointerToPositionList Pawn::getTakePossibilities()
{
    PointerToPositionList takePossibilities;
    
    if (player == Player::White)
    {
	takePossibilities.reset( new PositionList
	    {
		position.farther().left(), position.farther().right(),
		position.over().left(), position.over().right(), 
		position.farther().over()
	    } );
    } else { // it's Black!
	takePossibilities.reset( new PositionList
	    {
		position.closer().left(), position.closer().right(),
		position.under().left(), position.under().right(), 
		position.closer().under()
	    } );
    }
    
    return takePossibilities;
}



    
}
