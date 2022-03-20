// (C) Máté Gergely - gerymate@gmail.com
#include "catch2/catch.hpp"

#include "bishop.h"

SCENARIO("A Bishop is queryable", "[pieces]")
{
    GIVEN("A Bishop reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aBishop (new Model::Bishop);
	
	REQUIRE( aBishop->getFigure() == Model::Figure::Bishop );
    }
    
    GIVEN("There is a test failure")
    {
	REQUIRE( 1 == 0 );
    }
    
}


