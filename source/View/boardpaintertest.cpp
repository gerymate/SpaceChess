// (C) Máté Gergely - gerymate@gmail.com
#include "catch.hpp"

#include "boardpainter.h"
#include "game.h"

TEST_CASE( "Boards rect is computed correctly" )
{
    View::StyleSheet style {nullptr, nullptr};
    Model::Game aGame;
    View::BoardPainter aBoardPainter {nullptr, &style, &aGame, nullptr};
    
    sf::FloatRect board { aBoardPainter.getRect() };
    
    REQUIRE ( board.left == 0.0f );
    REQUIRE ( board.top == 0.0f );
    REQUIRE ( board.width == 322.5f );
    REQUIRE ( board.height == 349.0f );   
    
    style.setBoardSize (100);
    board = aBoardPainter.getRect();

    REQUIRE ( board.left == 0.0f );
    REQUIRE ( board.top == 0.0f );
    REQUIRE ( board.width == 107.5f );
    REQUIRE ( board.height == 116.0f );       
}
