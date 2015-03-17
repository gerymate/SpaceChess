#include "catch.hpp"
#include "Model/knight.h"

SCENARIO("A Knight is queryable", "[pieces]")
{
    GIVEN("A Knight reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aKnight (new Model::Knight);
	
	REQUIRE( aKnight->getFigure() == Model::Figure::Knight );
    }
    
}


