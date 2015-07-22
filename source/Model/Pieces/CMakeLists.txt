set(SOURCES
    piece.cpp king.cpp queen.cpp rook.cpp bishop.cpp knight.cpp unicorn.cpp pawn.cpp
    )
    
set(TEST_SOURCES piecestest.cpp
    piecetest.cpp kingtest.cpp queentest.cpp rooktest.cpp bishoptest.cpp knighttest.cpp unicorntest.cpp pawntest.cpp
)

add_library(SpaceChessPieces ${SOURCES})
add_executable(SpaceChessPiecesTests ${TEST_SOURCES})

target_link_libraries(SpaceChessPiecesTests SpaceChessModel )

add_test(Pieces_test SpaceChessPiecesTests)
