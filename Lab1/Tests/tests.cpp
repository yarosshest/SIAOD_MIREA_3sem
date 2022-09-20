#include <gtest/gtest.h>
#include "../task.cpp"
TEST(to_ones, test) {
    EXPECT_EQ(81921, to_ones(0));
}

TEST(to_zeros, test) {
    EXPECT_EQ(1009, to_zeros(1023));
}

TEST(mult, test) {
    EXPECT_EQ(64, mult(1));
}

TEST(division, test) {
    EXPECT_EQ(1, division(64));
}

TEST(to_zero_n, test) {
    EXPECT_EQ(991, to_zero_n(1023, 5));
}