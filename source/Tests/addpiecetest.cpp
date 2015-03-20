#include "catch.hpp"

#include "board.h"
#include "king.h"
#include "addpiece.h"

SCENARIO("An AddPiece GameEvent adds and removes pieces from and to a board", "[gameevents]")
{
    using namespace Model;
    GIVEN("An empty board and a pointer to an AddPiece GameEvent")
    {
	Board board;

	Position pos {3, 3, 3};
	PointerToPiece aKing {new King};
	PointerToGameEvent aGameEvent {new AddPiece {pos, aKing} };
	aGameEvent->setBoard(&board);
	
	REQUIRE ( board.getPiece(pos) == nullptr );
	
	WHEN("the event of adding a king is executed")
	{
	    REQUIRE ( aGameEvent->execute() == true );
	    
	    THEN("there is the king on the board")
	    {
		REQUIRE ( board.getPiece(pos) == aKing );
		
		WHEN("the event is reverted")
		{
		    aGameEvent->revert();
		    THEN("the king is removed from the board")
		    {
			REQUIRE ( board.getPiece(pos) == nullptr );
		    }
		}
	    }
	    
	    
	}
    }
    
}


