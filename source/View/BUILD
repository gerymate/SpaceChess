
cc_library(
    name = "SpaceChessView",
    srcs = glob(["*.cpp"], exclude=["*test*.cpp"]),
    hdrs = glob(["*.h"]),
    deps = ["//Common", "//Util:SpaceChessUtil", "//Model:SpaceChessModel", "@sfml//:graphics", "@sfml//:window", "@sfml//:system"],
    visibility = ["//main:__pkg__", "//:__pkg__"],
)

cc_test(
    name = "SpaceChessViewTests",
    srcs = glob(["*test.cpp"]),
    includes = ["../Model/"],
    deps = [
        "@catch2",
        "//test:catch-main",
        ":SpaceChessView",
    ],
)

