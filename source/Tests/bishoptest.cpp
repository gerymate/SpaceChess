#include "catch.hpp"
#include "Model/bishop.h"

SCENARIO("A Bishop is queryable", "[pieces]")
{
    GIVEN("A Bishop reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aBishop (new Model::Bishop);
	
	REQUIRE( aBishop->getFigure() == Model::Figure::Bishop );
    }
    
}

