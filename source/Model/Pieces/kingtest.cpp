// (C) Máté Gergely - gerymate@gmail.com
#include "catch.hpp"

#include "piece.h"
#include "king.h"
#include "board.h"

using namespace Model;

SCENARIO("A King is queryable", "[pieces]")
{
    GIVEN("A King reached through a shared pointer to a Piece")
    {
	std::shared_ptr<Model::Piece> aKing (new Model::King);
	
	REQUIRE( aKing->getFigure() == Model::Figure::King );
    }
}

SCENARIO("A King follows the move rules it has")
{
    Board boardRep;
    Board* board = &boardRep;
    
    GIVEN("a King in the middle of the board")
    {
	PointerToPiece aKing = Piece::generatePiece("wKCc3", board);
	/*
	PositionList legalMoves {
	    "Bb2", "Bb3", "Bb4", "Bc2", "Bc3", "Bc4", "Bd2", "Bd3", "Bd4",
	    "Cb2", "Cb3", "Cb4", "Cc2",        "Cc4", "Cd2", "Cd3", "Cd4",
	    "Db2", "Db3", "Db4", "Dc2", "Dc3", "Dc4", "Dd2", "Dd3", "Dd4"
	};
	*/
	
    }
    
    
    
    
}


