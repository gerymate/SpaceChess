set(TEST_SOURCES misctests.cpp
    piecetest.cpp
    kingtest.cpp queentest.cpp rooktest.cpp knighttest.cpp unicorntest.cpp pawntest.cpp movetest.cpp
    positiontest.cpp historytest.cpp
    )

add_executable(MiscTests ${TEST_SOURCES})

target_link_libraries(MiscTests SpaceChessModel SpaceChessView2D SpaceChessController )

add_test(Misc_tests MiscTests)