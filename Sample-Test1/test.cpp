#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/cal.cpp"

using namespace testing;

TEST(TestCaseName, TestName)
{
    EXPECT_THAT(1, Eq(1));

    vector<int> arr = { 1, 2, 3 };
    EXPECT_THAT(arr, Contains(3));

    vector<int> arr1;
    EXPECT_THAT(arr1, IsEmpty());
}

TEST(TestCaseName, TestName2)
{
    vector<int> input = { 1, 2, 3, 2 };
    vector<int> expect = { 2, 3, 5, 3 };
    Cal c;
    vector<int> actual = c.getResult(input);

    EXPECT_EQ(expect, actual);
    EXPECT_THAT(expect, ContainerEq(actual));
}

TEST(TestCaseName, TestName3)
{
    vector<int> input = { 9, 9, 3, 3 };
    vector<int> expect = { 0, 0, 5, 5 };
    Cal c;
    vector<int> actual = c.getResult(input);

    EXPECT_EQ(expect, actual);
    EXPECT_THAT(expect, ContainerEq(actual));
}

TEST(TestCaseName, TestName4)
{
    vector<int> input = { 10, 10, 10, 10 };
    Cal c;

    try
    {
        vector<int> actual = c.getResult(input);
    }
    catch (invalid_argument& e)
    {
        string temp = e.what();
        EXPECT_THAT(string("INV"), ContainerEq(temp));
    }
}
