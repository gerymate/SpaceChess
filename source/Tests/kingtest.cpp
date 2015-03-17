#include "catch.hpp"
#include "Model/king.h"

SCENARIO("A King is queryable", "[pieces]")
{
    GIVEN("A King reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aKing (new Model::King);
	
	REQUIRE( aKing->getFigure() == Model::Figure::King );
    }
    
}


