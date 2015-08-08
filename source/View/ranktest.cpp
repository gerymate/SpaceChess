// (C) Máté Gergely - gerymate@gmail.com
#include "catch.hpp"

#include "rank.h"
#include <cmath>

TEST_CASE( "A rank is where we put it")
{
    sf::Vector2f center {10.0, 20.0};
    View::StyleSheet styleSheet {nullptr, nullptr};
    int rankNumber {3};
    double size {styleSheet.PLANESIZE * pow(styleSheet.SCALEFACTOR, rankNumber)};
    double top {10.0 - size/2 };
    double left {20.0 - size/2 };
    Model::IBoardInfo * boardInfo {nullptr};
    View::Rank aRank {center, &styleSheet, rankNumber, boardInfo};

    REQUIRE( aRank.getRankNumber() == 3 );
    sf::FloatRect boundaries { aRank.getBoundaries() };
    REQUIRE( boundaries.left == left );
    REQUIRE( boundaries.top == top );
    REQUIRE( boundaries.width == size ); 
    REQUIRE( boundaries.height == size ); 
        
}


