#include "catch.hpp"

#include "piece.h"
using namespace Model;

SCENARIO("Pieces are generated based on strings", "[pieces]")
{
    GIVEN("A King is generated")
    {
	Position pos {"Aa1"};
	PointerToPiece aKing;
	
	REQUIRE_NOTHROW( aKing = Piece::generatePiece("wKAa1") );

	REQUIRE( aKing->getFigure() == Figure::King );
	REQUIRE( aKing->getPlayer() == Player::White );
	REQUIRE( aKing->getPosition() == pos );
    }

    GIVEN("An Unicorn is generated")
    {
	Position pos {"Cc3"};
	PointerToPiece anUnicorn;
	
	REQUIRE_NOTHROW( anUnicorn = Piece::generatePiece("bUCc3") );

	REQUIRE( anUnicorn->getFigure() == Figure::Unicorn );
	REQUIRE( anUnicorn->getPlayer() == Player::Black );
	REQUIRE( anUnicorn->getPosition() == pos );
    }
        
    GIVEN("generation fails from bad strings")
    {
	PointerToPiece aPiece;
	REQUIRE_THROWS( aPiece = Piece::generatePiece("rZAa4") );
    }
    
}


