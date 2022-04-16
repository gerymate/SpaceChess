
cc_library(
    name = "SpaceChessView",
    srcs = glob(["*.cpp"], exclude=["*test*.cpp"]),
    hdrs = glob(["*.h"]),
    deps = ["//Common", "//Util:SpaceChessUtil", "//Model:SpaceChessModel"],
    visibility = ["//main:__pkg__", "//:__pkg__"],
)

cc_test(
    name = "SpaceChessViewTests",
    srcs = [],
    deps = [
        "@catch2",
        "SpaceChessView"
    ],
)
