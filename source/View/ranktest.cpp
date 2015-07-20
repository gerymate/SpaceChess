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

    REQUIRE( aRank.getRank() == 3 );
    REQUIRE( aRank.getBoundaries().left == 10.0 );
    REQUIRE( aRank.getBoundaries().top == 20.0 );
        
}


