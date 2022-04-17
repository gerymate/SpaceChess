
cc_library(
    name = "SpaceChessModel",
    srcs = ["board.cpp", "history.cpp", "judge.cpp", "game.cpp", "field.cpp", "fullboard.cpp","gamestate.cpp", "position.cpp", "figure.cpp", "piece.cpp", "king.cpp", "queen.cpp", "rook.cpp", "bishop.cpp", "knight.cpp", "unicorn.cpp", "pawn.cpp", "gameevent.cpp", "creation.cpp", "move.cpp"],
    hdrs = glob(["*.h", "Common/i*.h"]),
    deps = ["//Common"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "SpaceChessModelTests",
    srcs = glob(["*test.cpp"]),
    deps = [
        "@catch2",
        "//test:catch-main",
        ":SpaceChessModel"
    ],
)
