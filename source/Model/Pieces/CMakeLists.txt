set(SOURCES
    piece.cpp king.cpp queen.cpp rook.cpp bishop.cpp knight.cpp unicorn.cpp pawn.cpp
    )
    
set(TEST_SOURCES piecestest.cpp
	bishoptest.cpp
)

add_library(SpaceChessPieces ${SOURCES})
add_executable(SpaceChessPiecesTests ${TEST_SOURCES})

target_link_libraries(SpaceChessPiecesTests SpaceChessModel SpaceChessView2D SpaceChessController )

add_test(Pieces_test SpaceChessPiecesTests)