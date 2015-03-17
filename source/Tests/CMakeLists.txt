set(TEST_SOURCES tests.cpp 
    kingtest.cpp queentest.cpp rooktest.cpp bishoptest.cpp knighttest.cpp unicorntest.cpp pawntest.cpp
    )

add_executable(Tests ${TEST_SOURCES})

add_test(All_tests Tests)

target_link_libraries(Tests SpaceChessModel SpaceChessView2D SpaceChessControllers )
