// (C) Máté Gergely - gerymate@gmail.com
#include "catch.hpp"

#include "field.h"
#include "piece.h"
//#include "stylesheet.h"

TEST_CASE( "A Field at Aa1 with a Bishop on it" )
{
    const sf::Vector2f topLeft { 10.0, 20.0 };
    const float scaleFactor { 1.0 };
    View::StyleSheet styleSheet {nullptr, nullptr};
    const Model::PointerToPiece aBishopInTheCorner = Model::Piece::generatePiece("bBAa1", nullptr);
    const Model::Position realPlaceOnBoard {"Aa1"};
    const Model::Position unusedParameter {"Cd4"};

    View::Field aField (topLeft, scaleFactor, &styleSheet, aBishopInTheCorner, unusedParameter);

    REQUIRE ( aField.getPosition() == realPlaceOnBoard );
    REQUIRE ( aField.getPosition() != unusedParameter );
    
    sf::FloatRect boundaries { aField.getBoundaries() };
    REQUIRE ( boundaries.top == topLeft.y );
    REQUIRE ( boundaries.left == topLeft.x );
    REQUIRE ( boundaries.width == styleSheet.getFieldSize() );
    REQUIRE ( boundaries.height == styleSheet.getFieldSize() );
 
}

TEST_CASE( "Empty field on Cc3" )
{
    const sf::Vector2f topLeft { 50.0, 100.0 };
    const float scaleFactor { 1.0 };
    View::StyleSheet styleSheet {nullptr, nullptr};
    const Model::Position placeOnBoard {"Cc3"};

    View::Field aField (topLeft, scaleFactor, &styleSheet, nullptr, placeOnBoard);

    REQUIRE ( aField.getPosition() == placeOnBoard );
    
    sf::FloatRect boundaries { aField.getBoundaries() };
    REQUIRE ( boundaries.top == topLeft.y );
    REQUIRE ( boundaries.left == topLeft.x );
    REQUIRE ( boundaries.width == styleSheet.getFieldSize() );
    REQUIRE ( boundaries.height == styleSheet.getFieldSize() );
    
    REQUIRE ( ! aField.isUnderCursor() ); //default
    aField.setUnderCursor();
    REQUIRE ( aField.isUnderCursor() );
    aField.notUnderCursor();
    REQUIRE ( ! aField.isUnderCursor() );
        
}

TEST_CASE( "static method isWhiteField reports well?" )
{
    Model::Position Aa1 {"Aa1"};
    Model::Position Aa2 {"Aa2"};
    Model::Position Ab1 {"Ab1"};
    Model::Position Ba1 {"Ba1"};

    REQUIRE( ! View::Field::isWhiteField(Aa1) );
    REQUIRE( View::Field::isWhiteField(Aa2) );
    REQUIRE( View::Field::isWhiteField(Ab1) );
    REQUIRE( View::Field::isWhiteField(Ba1) );
    
}
