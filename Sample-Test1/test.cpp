#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/cal.cpp"

TEST(TestCaseName, TestName)
{
    Cal c;
    int ret = c.getSum(1, 1);
    EXPECT_EQ(ret, 2);
}