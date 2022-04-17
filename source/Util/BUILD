
cc_library(
    name = "SpaceChessUtil",
    srcs = ["timelychangingvalue.cpp"],
    hdrs = ["timelychangingvalue.h"],
    visibility = ["//main:__pkg__", "//View:__pkg__"],
)

cc_test(
    name = "SpaceChessUtilTests",
    srcs = ["timelychangingvaluetest.cpp"],
    deps = [
        "@catch2",
        "//test:catch-main",
        "SpaceChessUtil"
    ],
)
