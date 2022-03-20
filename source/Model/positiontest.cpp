// (C) Máté Gergely - gerymate@gmail.com
#include "catch2/catch.hpp"

#include "position.h"

using namespace Model;

SCENARIO("Positions are comparable", "[position]")
{
    GIVEN("Two positions are equal")
    {
	Position p1 {1, 1, 1}, p2 {1, 1, 1} ;
	
	REQUIRE( ! (p1 < p2) );
	REQUIRE( ! (p2 < p1) );
    }
    
    GIVEN("Position p1 is on level A and position p2 is on level B")
    {
	Position p1 {0, 0, 0}, p2 {1, 2, 3} ;
	
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
    Position p1 {"Aa1"};
    
    REQUIRE( p1.isValid() );
    REQUIRE( p1.getLevel() == 0 );
    REQUIRE( p1.getFile() == 0 );
    REQUIRE( p1.getRank() == 0 );
    
    Position p2 {"Ee5"};
    
    REQUIRE( p2.isValid() );
    REQUIRE( p2.getLevel() == 4 );
    REQUIRE( p2.getFile() == 4 );
    REQUIRE( p2.getRank() == 4 );

    WHEN("that position is asked back in notation")
    {
	REQUIRE( p1.getNotation() == "Aa1" );
	REQUIRE( p2.getNotation() == "Ee5" );
    }

    REQUIRE_THROWS( Position("#") );
    REQUIRE_THROWS( Position("Eh3") );
}

SCENARIO("There are positions around a central position")
{
    Position pos {"Cc3"};
    
    REQUIRE( pos.over().under() == pos );
    REQUIRE( pos.left().right() == pos );
    REQUIRE( pos.farther().closer() == pos);
    
    REQUIRE( pos.under().getLevel() == pos.getLevel() - 1 );
    REQUIRE( pos.under().getFile() == pos.getFile() );
    REQUIRE( pos.under().getRank() == pos.getRank() );    
    
    REQUIRE( pos.over() == Position {"Dc3"} );
    
    REQUIRE( pos.left().getLevel() == pos.getLevel() );
    REQUIRE( pos.left().getFile() == pos.getFile() - 1 );
    REQUIRE( pos.left().getRank() == pos.getRank() );

    REQUIRE( pos.right() == Position {"Cd3"} );    
    
    REQUIRE( pos.closer().getLevel() == pos.getLevel() );
    REQUIRE( pos.closer().getFile() == pos.getFile() );
    REQUIRE( pos.closer().getRank() == pos.getRank() - 1 );
    
    REQUIRE( pos.farther() == Position {"Cc4"} );
    
}

TEST_CASE ( "Valid positions are in the 5x5x5 board" )
{
    Position Aa1 {"Aa1"};
    Position Ee5 {"Ee5"};
    Position Ab3 {0, 1, 2};
    Position Cd5 {2, 3, 4};
    Position anInvalidOne {-1, 0, 0};
    Position anotherInvalidOne {4, 5, 5};

    REQUIRE ( Aa1.isValid() );
    REQUIRE ( Ee5.isValid() );
    REQUIRE ( Ab3.isValid() );
    REQUIRE ( Cd5.isValid() );
    REQUIRE ( ! anInvalidOne.isValid() );
    REQUIRE ( ! anotherInvalidOne.isValid() );
}

