//
// Created by yaros on 16.09.2022.
//
#include <gtest/gtest.h>

TEST(to_ones, test1) {
    int x = 0;
    int a = 1<<16;
    int b = 1<<14;
    int c = 1;
    int result = x|a|b|c;
    EXPECT_EQ(result, to_ones(x));
}