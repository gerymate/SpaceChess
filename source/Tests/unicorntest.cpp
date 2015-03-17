#include "catch.hpp"
#include "Model/unicorn.h"

SCENARIO("An Unicorn is queryable", "[pieces]")
{
    GIVEN("An Unicorn reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aUnicorn (new Model::Unicorn);
	
	REQUIRE( aUnicorn->getFigure() == Model::Figure::Unicorn );
    }
    
}


