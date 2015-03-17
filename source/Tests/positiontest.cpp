#include "catch.hpp"
#include "Model/position.h"

SCENARIO("Positions are comparable", "[position]")
{
    using namespace Model;
    GIVEN("Two positions are equal")
    {
	Position p1 {1, 1, 1}, p2 {1, 1, 1} ;
	
	REQUIRE( ! (p1 < p2) );
	REQUIRE( ! (p2 < p1) );
    }
    
    GIVEN("Position p1 is on level A and position p2 is on level B")
    {
	Position p1 {1, 1, 1}, p2 {2, 3, 4} ;
	
	REQUIRE( p1 < p2 );
	REQUIRE( ! (p2 < p1) );
    }
    
    GIVEN("Position p1 and p2 is on the same level but on different file")
    {
	Position p1 {3, 1, 1}, p2 {3, 3, 4} ;
	
	REQUIRE( p1 < p2 );
	REQUIRE( ! (p2 < p1) );
    }

    GIVEN("Position p1 and p2 is on the same level and file but on different rank")
    {
	Position p1 {3, 4, 1}, p2 {3, 4, 4} ;
	
	REQUIRE( p1 < p2 );
	REQUIRE( ! (p2 < p1) );
    }

    
}


