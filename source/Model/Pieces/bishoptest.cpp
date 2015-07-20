// (C) Máté Gergely - gerymate@gmail.com
#include "catch.hpp"

#include "bishop.h"

SCENARIO("A Bishop is queryable", "[pieces]")
{
    GIVEN("A Bishop reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aBishop (new Model::Bishop);
	
	REQUIRE( aBishop->getFigure() == Model::Figure::Bishop );
    }
    
}


