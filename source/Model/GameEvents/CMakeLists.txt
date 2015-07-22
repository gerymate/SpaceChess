set(SOURCES
    gameevent.cpp
    creation.cpp
    move.cpp
    )

add_library(SpaceChessGameEvents ${SOURCES})

set(TEST_SOURCES gameeventstests.cpp
    movetest.cpp
    )

add_executable(SpaceChessGameEventsTests ${TEST_SOURCES})

target_link_libraries(SpaceChessGameEventsTests SpaceChessModel )

add_test(GameEvent_tests SpaceChessGameEventsTests)
