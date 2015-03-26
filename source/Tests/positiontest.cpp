#include "catch.hpp"

#include "position.h"

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

SCENARIO("Positions are generated from notation")
{
    using namespace Model;

    Position p1 {"Aa1"};
    
    REQUIRE( p1.isValid() );
    REQUIRE( p1.getLevel() == 1 );
    REQUIRE( p1.getFile() == 1 );
    REQUIRE( p1.getRank() == 1 );

    Position p2 {"Ee5"};
    
    REQUIRE( p2.isValid() );
    REQUIRE( p2.getLevel() == 5 );
    REQUIRE( p2.getFile() == 5 );
    REQUIRE( p2.getRank() == 5 );

    REQUIRE_THROWS( Position p3 {"#"} );
    REQUIRE_THROWS( Position p4 {"Eh3"} );

    
}


