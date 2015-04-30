set(TEST_SOURCES tests.cpp 
    piecetest.cpp
    kingtest.cpp queentest.cpp rooktest.cpp bishoptest.cpp knighttest.cpp unicorntest.cpp pawntest.cpp
    addpiecetest.cpp movetest.cpp
    positiontest.cpp boardtest.cpp historytest.cpp
    )

add_executable(Tests ${TEST_SOURCES})

add_test(All_tests Tests)

target_link_libraries(Tests SpaceChessModel SpaceChessView2D SpaceChessController )
