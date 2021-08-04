#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
}

TEST(HelloTest, Assert2)
{
    EXPECT_EQ(5*5, 25);
}