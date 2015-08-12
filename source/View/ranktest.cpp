// (C) Máté Gergely - gerymate@gmail.com
#include "catch.hpp"

#include "rank.h"
#include <cmath>

TEST_CASE( "A rank is where we put it")
{
    sf::Vector2f center {10.0, 20.0};
    View::StyleSheet styleSheet {nullptr, nullptr};
    int rankNumber {3};
    float realScale {(float)pow((float)styleSheet.SCALEFACTOR, rankNumber)};
    float size {(float)styleSheet.getBoardSize() * realScale};
    float top {20.0f - size/2 };
    float left {10.0f - size/2 };
    Model::IBoardInfo * boardInfo {nullptr};
    View::Rank aRank {&styleSheet, rankNumber, boardInfo};

    REQUIRE( aRank.getRankNumber() == 3 );
    sf::FloatRect boundaries { aRank.getRect() };
    REQUIRE( boundaries.left == left );
    REQUIRE( boundaries.top == top );
    REQUIRE( boundaries.width == size ); 
    REQUIRE( boundaries.height == size ); 
    
    REQUIRE( aRank.width() == size );
    REQUIRE( aRank.height() == size );
    REQUIRE( aRank.topLeft().y == top );
    REQUIRE( aRank.topLeft().x == left );
}


