cc_library(
    name="SpaceChessController",
    srcs=glob(["Controller/*.cpp"]),
    hdrs=glob(["**/*.h"]),
    deps=["//Common", "//Model:SpaceChessModel", "@sfml//:network"],
    visibility=["//main:__pkg__"],
)

cc_library(
    name="SpaceChessCore",
    srcs=glob(["event.cpp", "core.cpp", "log.cpp"]),
    hdrs=glob(["*.h"]),
    deps=["//Common", "//Model:SpaceChessModel"],
    visibility=["//main:__pkg__"],
)

cc_binary(
    name="SpaceChess",
    srcs=["app.cpp", "main.cpp", "app.h"],
    deps=[":SpaceChessCore", ":SpaceChessController", "//View:SpaceChessView"],
)

