#include "catch.hpp"

#include "board.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
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
		REQUIRE( aGameEvent->getNotation() == std::string("Cc3 Cc4") );

		
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
    
    GIVEN("a Pawn (on the last line) that wants to be a Queen")
    {
	Board board;
	Position src {5, 3, 4};
	Position dest {5, 3, 5};
	PointerToPiece aPawn {new Pawn};
	PointerToPiece aQueen {new Queen};

	board.addPiece(src, aPawn);
	
	PointerToGameEvent aGameEvent {new Move {src, dest, aQueen}};
	aGameEvent->setBoard(&board);
	
	WHEN("the promotion is executed")
	{
	    REQUIRE( board.getPiece(src) == aPawn ); 
	    REQUIRE( board.isOccupied(dest) == false ); 
	    
	    REQUIRE( aGameEvent->execute() == true );
	    
	    REQUIRE( board.getPiece(dest) == aQueen ); 
	    REQUIRE( board.isOccupied(src) == false );
	    REQUIRE( aGameEvent->getNotation() == std::string("Ec4 Ec5=Q") );	    

	    THEN("the promotion is reverted")
	    {
		REQUIRE( aGameEvent->revert() == true );
		REQUIRE( board.getPiece(src) == aPawn ); 
		REQUIRE( board.isOccupied(dest) == false );
	    }
	}
    }

    GIVEN("a Pawn near a Queen")
    {
	Board board;
	Position src {3, 3, 3};
	Position dest {3, 3, 4};
	PointerToPiece aPawn {new Pawn};
	PointerToPiece aQueen {new Queen};

	board.addPiece(src, aPawn);
	board.addPiece(dest, aQueen);

	PointerToGameEvent aGameEvent {new Move {src, dest}};
	aGameEvent->setBoard(&board);
	
	REQUIRE( board.getPiece(src) == aPawn ); 
	REQUIRE( board.getPiece(dest) == aQueen ); 

	WHEN("the pawn takes the queen")
	{	    
	    REQUIRE( aGameEvent->execute() == true );
	    
	    REQUIRE( board.getPiece(dest) == aPawn ); 
	    REQUIRE( board.isOccupied(src) == false );
	    REQUIRE( aGameEvent->getNotation() == std::string("Cc3xCc4") );	    

	    THEN("the take is reverted")
	    {
		REQUIRE( aGameEvent->revert() == true );
		REQUIRE( board.getPiece(src) == aPawn ); 
		REQUIRE( board.getPiece(dest) == aQueen );
	    }
	}
    }

    
    
}


