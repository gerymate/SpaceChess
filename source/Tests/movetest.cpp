#include "catch.hpp"

#include "board.h"
#include "king.h"
#include "addpiece.h"
#include "move.h"

SCENARIO("A King moves on the board", "[gameevents]")
{
    using namespace Model;
    GIVEN("a King ")
    {
	Board board;
	Position src {3, 3, 3};
	Position dest {3, 3, 4};
	PointerToPiece aKing {new King};
	board.addPiece(src, aKing);
	
	PointerToGameEvent aGameEvent {new Move {src, dest} };
	aGameEvent->setBoard(&board);

	REQUIRE( aGameEvent->revert() == false );	
	
	WHEN("the event of moving the king is executed")
	{
	    REQUIRE ( aGameEvent->execute() == true );
	    
	    THEN("the king has moved")
	    {
		REQUIRE ( board.getPiece(src) == nullptr );
		REQUIRE ( board.getPiece(dest) == aKing );
		
		WHEN("the event is reverted")
		{
		    REQUIRE( aGameEvent->revert() == true );
		    THEN("the king is back")
		    {
			REQUIRE ( board.getPiece(dest) == nullptr );
			REQUIRE ( board.getPiece(src) == aKing );
		    }
		}
	    }
	    THEN("you can't make the same move again")
	    {
		REQUIRE ( aGameEvent->execute() == false );
	    }
	}
    }
}


