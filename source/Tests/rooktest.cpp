#include "catch.hpp"

#include "rook.h"

SCENARIO("A Rook is queryable", "[pieces]")
{
    GIVEN("A Rook reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aRook (new Model::Rook);
	
	REQUIRE( aRook->getFigure() == Model::Figure::Rook );
    }
    
}


