#include "catch.hpp"

#include "board.h"
#include "king.h"
#include "queen.h"

SCENARIO("Pieces can be added and get from a Board", "[board]")
{
    using namespace Model;
    GIVEN("An empty board")
    {
	Board board;
	Position pos {3, 3, 3};
	REQUIRE ( board.getPiece(pos) == nullptr );
	
	WHEN("A piece is added to the board")
	{
	    PointerToPiece aKing {new King};
	    REQUIRE ( board.addPiece(pos, aKing) == true );
	    
	    THEN("you can't add another piece to the same place")
	    {
		PointerToPiece aQueen {new Queen};
		REQUIRE ( board.addPiece(pos, aQueen) == false );
	    }
	    
	    THEN("you get your piece back by querying that place")
	    {
		REQUIRE ( board.getPiece(pos) == aKing );
	    }

	    THEN("that place is occupied")
	    {
		REQUIRE ( board.isOccupied(pos) );
	    }
	    
	    WHEN("you remove that piece")
	    {
		REQUIRE( board.removePiece(pos) == true );
		
		THEN("the piece is removed")
		{
		    REQUIRE ( board.isOccupied(pos) == false );    
		}
	    }
	}
    }
    
}


