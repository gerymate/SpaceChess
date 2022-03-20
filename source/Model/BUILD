
cc_library(
    name = "SpaceChessModel",
    srcs = ["board.cpp", "history.cpp", "judge.cpp", "game.cpp", "field.cpp", "fullboard.cpp","gamestate.cpp", "position.cpp", "figure.cpp", "piece.cpp", "king.cpp", "queen.cpp", "rook.cpp", "bishop.cpp", "knight.cpp", "unicorn.cpp", "pawn.cpp", "gameevent.cpp", "creation.cpp", "move.cpp"],
    hdrs = glob(["*.h"]),
    deps = ["//Common"],
    visibility = ["//main:__pkg__"],
)

cc_test(
    name = "SpaceChessModelTests",
    srcs = ["modeltests.cpp", "boardtest.cpp", "historytest.cpp", "positiontest.cpp", "piecetest.cpp", "kingtest.cpp", "queentest.cpp", "rooktest.cpp", "bishoptest.cpp", "knighttest.cpp", "unicorntest.cpp", "pawntest.cpp", "movetest.cpp"],
    deps = [
        "@catch2",
        "SpaceChessModel"
    ],
)
