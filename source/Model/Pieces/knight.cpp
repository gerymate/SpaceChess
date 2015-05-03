#include "knight.h"

namespace Model
{

PointerToPositionList Knight::getPossibleMoves()
{
    PointerToPositionList basicPossibilities { new PositionList {
// plane with normal y
		position.farther().farther().left(), position.farther().farther().right(),
		position.right().right().farther(), position.right().right().closer(),
		position.closer().closer().right(), position.closer().closer().left(),
		position.left().left().closer(), position.left().left().farther(),
// plane with normal x
		position.over().over().closer(), position.over().over().farther(),
		position.farther().farther().over(), position.farther().farther().under(),
		position.under().under().farther(), position.under().under().closer(),
		position.closer().closer().under(), position.closer().closer().over(),
// plane with normal z
		position.over().over().left(), position.over().over().right(),
		position.right().right().over(), position.right().right().under(),
		position.under().under().right(), position.under().under().left(),
		position.left().left().under(), position.left().left().over()
	    } 
	};
	    
    filterForMoveOrTake(basicPossibilities);
	    
    return basicPossibilities;    
}
    
    
    
}
