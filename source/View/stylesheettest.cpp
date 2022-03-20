// (C) Máté Gergely - gerymate@gmail.com
#include "catch2/catch.hpp"

#include "stylesheet.h"

TEST_CASE( "Sizes are computed correctly" )
{
    View::StyleSheet style (nullptr, nullptr);
    
    style.setBoardSize(200.0f); // original size
    
    REQUIRE ( style.getBoardSize() == 200.0f );
    REQUIRE ( style.getFieldSize() == 40.0f );
    REQUIRE ( style.getViewPortScale() == 1.0f );
    REQUIRE ( style.getMarginSize() == 30.0f );
    REQUIRE ( style.getBoardCenter().x == 130.0f );
    REQUIRE ( style.getBoardCenter().y == 130.0f );

    style.setBoardSize(300.0f);
    
    REQUIRE ( style.getBoardSize() == 300.0f );
    REQUIRE ( style.getFieldSize() == 60.0f );
    REQUIRE ( style.getViewPortScale() == 1.5f );
    REQUIRE ( style.getMarginSize() == 45.0f );
    REQUIRE ( style.getBoardCenter().x == 195.0f );
    REQUIRE ( style.getBoardCenter().y == 195.0f );
 
}
