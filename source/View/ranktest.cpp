// (C) Máté Gergely - gerymate@gmail.com
#include "catch.hpp"

#include "rank.h"

TEST_CASE( "A rank is where we put it")
{
    sf::Vector2f topLeftCorner {10.0, 20.0};
    View::StyleSheet styleSheet {nullptr, nullptr};
    int rankNumber {3};
    Model::IBoardInfo * boardInfo {nullptr};
    View::Rank aRank {topLeftCorner, &styleSheet, rankNumber, boardInfo};

    REQUIRE( aRank.getRankNumber() == 3 );
    sf::FloatRect boundaries { aRank.getBoundaries() };
    REQUIRE( boundaries.left == 10.0 );
    REQUIRE( boundaries.top == 20.0 );
    REQUIRE( boundaries.width == styleSheet.PLANESIZE ); 
    REQUIRE( boundaries.height == styleSheet.PLANESIZE ); 
        
}


