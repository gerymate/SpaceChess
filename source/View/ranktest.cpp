// (C) Máté Gergely - gerymate@gmail.com
#include "catch2/catch.hpp"

#include "rank.h"
#include <cmath>

TEST_CASE( "A rank is where we put it")
{
    View::StyleSheet styleSheet {nullptr, nullptr};
    sf::Vector2f center {styleSheet.getBoardCenter()};
    int rankNumber {3};
    float realScale {(float)pow((float)styleSheet.SCALEFACTOR, rankNumber)};			
    float size {(float)styleSheet.getBoardSize() * realScale};
    float top {center.y - size / 2.0f };
    float left {center.x - size / 2.0f };
    Model::IBoardInfo * boardInfo {nullptr};
    View::Rank aRank {&styleSheet, rankNumber, boardInfo};

    REQUIRE( aRank.getRankNumber() == rankNumber );
    sf::FloatRect boundaries { aRank.getRect() };
    REQUIRE( boundaries.width == size ); 
    REQUIRE( boundaries.height == size ); 
    REQUIRE( boundaries.left == left );
    REQUIRE( boundaries.top == top );
    
    REQUIRE( aRank.width() == size );
    REQUIRE( aRank.height() == size );
    REQUIRE( aRank.topLeft().y == top );
    REQUIRE( aRank.topLeft().x == left );
}


