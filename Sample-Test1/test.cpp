#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/cal.cpp"

using namespace testing;


TEST(DBSYSTEM, DB001)
{
    DBAPI& db = DatabaseAPI();

    LogSystem app(&db);
    cout << app.getLogMessage("Very GG");
}

class MockDB : public DBAPI
{
public:
    MOCK_METHOD(string, getDBName, (), (override));
};

TEST(DBSYSTEM, DB002)
{
    MockDB db;
    EXPECT_CALL(db, getDBName())
        .WillRepeatedly(Return(string{ "FACK_DB" }));

    LogSystem app(&db);
    cout << app.getLogMessage("Very GG");
}

class MockCal : public Cal
{
public:
    MOCK_METHOD(int, getSum, (int a, int b), ());
    MOCK_METHOD(int, getValue, (), ());
};

TEST(CalTest, CalMock77)
{
    MockCal mc;

    EXPECT_CALL(mc, getValue)
        .Times(2) // behavior verification
        .WillRepeatedly(Return(10000)); // stub

    // state verification
    int value = mc.getValue();
    EXPECT_THAT(value, Eq(10000));
    EXPECT_THAT(mc.getValue(), Eq(10000));
}

TEST(CalTest, CalMock)
{
    MockCal mc;

    // behavior verification
    EXPECT_CALL(mc, getSum(1, 2))
        .Times(2);
    
    int ret1 = mc.getSum(1, 2);
    int ret2 = mc.getSum(1, 2);
}

TEST(CalTest, CalMock2)
{
    MockCal mc;

    // behavior verification & sturbbing 동시사용
    EXPECT_CALL(mc, getSum(1, 2))
        .Times(2)
        .WillRepeatedly(Return(100));

    int ret1 = mc.getSum(1, 2);
    int ret2 = mc.getSum(1, 2);
}


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
