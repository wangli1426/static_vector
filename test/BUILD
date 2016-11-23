cc_test(
    name = "test",
    srcs = ["vector-test.cc", "unordered_map-test.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        "//lib:static_vector",
    ],
    size = "small",
)
