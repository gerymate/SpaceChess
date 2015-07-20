// (C) Máté Gergely - gerymate@gmail.com
#include "catch.hpp"

#include "fieldcontent.h"
#include "piece.h"

TEST_CASE( "Empty field content" )
{
    View::FieldContent fc {nullptr};
    REQUIRE( fc.owner == Model::Player::Nobody );
    REQUIRE( fc.figure == Model::Figure::None );
    REQUIRE( fc.position == Model::Position::Invalid );
}

TEST_CASE( "Empty field content with position Aa1" )
{
    View::FieldContent fc {nullptr, Model::Position("Aa1")};
    REQUIRE( fc.owner == Model::Player::Nobody );
    REQUIRE( fc.figure == Model::Figure::None );
    REQUIRE( fc.position == Model::Position(1, 1, 1) );
}

TEST_CASE( "Field content from a pointer to a king in the corner" )
{
    Model::PointerToPiece aKingInTheCorner = Model::Piece::generatePiece("bKAa1", nullptr);
    View::FieldContent fc {aKingInTheCorner, Model::Position("Bb2")};
    REQUIRE( fc.owner == Model::Player::Black );
    REQUIRE( fc.figure == Model::Figure::King );
    REQUIRE( fc.position == Model::Position("Aa1") );
}

TEST_CASE( "Field content from a pointer to a pawn in the center" )
{
    Model::PointerToPiece aPawnInTheCenter = Model::Piece::generatePiece("wPCc3", nullptr);
    View::FieldContent fc {aPawnInTheCenter, Model::Position("Aa1")};
    REQUIRE( fc.owner == Model::Player::White );
    REQUIRE( fc.figure == Model::Figure::Pawn );
    REQUIRE( fc.position == Model::Position("Cc3") );
}
