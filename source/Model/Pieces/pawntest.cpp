// (C) Máté Gergely - o7djsn - sportember@caesar.elte.hu
#include "catch.hpp"

#include "pawn.h"

SCENARIO("A Pawn is queryable", "[pieces]")
{
    GIVEN("A Pawn reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aPawn (new Model::Pawn);
	
	REQUIRE( aPawn->getFigure() == Model::Figure::Pawn );
    }
    
}


