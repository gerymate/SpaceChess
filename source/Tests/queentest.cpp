#include "catch.hpp"

#include "Model/queen.h"

SCENARIO("A Queen is queryable", "[pieces]")
{
    GIVEN("A Queen reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aQueen (new Model::Queen);
	
	REQUIRE( aQueen->getFigure() == Model::Figure::Queen );
    }
    
}


