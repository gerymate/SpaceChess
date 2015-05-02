#include "pawn.h"

namespace Model
{
    
PointerToPositionList Pawn::getPossibleMoves()
{
    PointerToPositionList movePossibilities;
    PointerToPositionList takePossibilities;
    
    if (player == Player::White)
    {
	movePossibilities.reset( new PositionList { position.farther(), position.over() } );
	takePossibilities.reset( new PositionList
	    {
		position.farther().left(), position.farther().right(),
		position.over().left(), position.over().right(), 
		position.farther().over()
	    } );
    } else { // it's Black!
	movePossibilities.reset( new PositionList { position.closer(), position.under() } );
	takePossibilities.reset( new PositionList
	    {
		position.closer().left(), position.closer().right(),
		position.under().left(), position.under().right(), 
		position.closer().under()
	    } );
    }

    filterForMove(movePossibilities);
    filterForTake(takePossibilities);
    
    movePossibilities->splice(movePossibilities->begin(), *takePossibilities);

    return movePossibilities;    
}
    
    
}
