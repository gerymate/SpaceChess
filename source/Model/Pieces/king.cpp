#include "king.h"

namespace Model
{

PositionList King::getPossibleMoves()
{
    PositionList basicPossibilities {
	position.over().farther().left() , position.over().farther() , position.over().farther().right(),
	position.over().left()		 , position.over()           , position.over().right(),
	position.over().closer().left()  , position.over().closer()  , position.over().closer().right(),
	
	position.farther().left()        , position.farther()        , position.farther().right(),
	position.left()						     , position.right(),
	position.closer().left()         , position.closer()         , position.closer().right(),
	
	position.under().farther().left(), position.under().farther(), position.under().farther().right(),
	position.under().left()    	 , position.under()	     , position.under().right(),
	position.under().closer().left() , position.under().closer() , position.under().closer().right()
    };
    
    basicPossibilities.remove_if([](Position p){ return ! (p.isValid()); });

    return basicPossibilities;
}

    
    
    
}