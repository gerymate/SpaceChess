#include "catch.hpp"

#include "history.h"
#include "gameevent.h"
#include "king.h"
#include "queen.h"

SCENARIO("We test a new game history", "[history]")
{
    using namespace Model;
    GIVEN("a new history")
    {
	Board board;
	History history { &board };
	
	REQUIRE ( history.getNextPlayer() == Player::Nobody );
	
	WHEN("we try to step back beyond creation")
	{
	    REQUIRE( history.stepBack() == false );

	    PointerToGameEvent shouldBeCreation = history.getCurrentEvent();
	    REQUIRE ( shouldBeCreation->getNotation() == "Game created." );
	    
	    THEN("nothing to do yet")
	    {
		REQUIRE ( history.actualize() == false );
	    }	    
	}
    }
    
}


