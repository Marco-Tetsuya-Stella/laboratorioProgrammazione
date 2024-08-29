#include "gtest/gtest.h"
#include "../Time.h"

TEST(Time,Constructor) {
    Time time1(1, 2, 13);
    ASSERT_EQ(time1.getHour(), 1);
    ASSERT_EQ(time1.getMinute(), 2);
    ASSERT_EQ(time1.getSecond(), 13);

    Time time2(0, 0, 0);
    ASSERT_EQ(time2.getHour(), 0);
    ASSERT_EQ(time2.getMinute(), 0);
    ASSERT_EQ(time2.getSecond(), 0);

    Time time3(23, 59, 59);
    ASSERT_EQ(time3.getHour(), 23);
    ASSERT_EQ(time3.getMinute(), 59);
    ASSERT_EQ(time3.getSecond(), 59);


    ASSERT_THROW(Time time4(-10,1,1),std::invalid_argument);
    ASSERT_THROW(Time time5(1,-10,1),std::invalid_argument);
    ASSERT_THROW(Time time6(1,1,-10),std::invalid_argument);
    ASSERT_THROW(Time time7(24,60,60),std::invalid_argument);


    Time time8(01,01,01);
    ASSERT_EQ(time8.getHour(),01);
    ASSERT_EQ(time8.getMinute(),01);
    ASSERT_EQ(time8.getSecond(),01);
}

TEST(Time,Operators) {
    Time time1(12,12,12);
    Time time2(12,12,12);
    ASSERT_TRUE(time1 == time2);
    ASSERT_FALSE(time1 < time2);
    time2.setSecond(13);
    ASSERT_TRUE(time1 < time2);
    time2.setSecond(11);
    time2.setMinute(13);
    ASSERT_TRUE(time1 < time2);
    time2.setMinute(11);
    time2.setHour(13);
    ASSERT_TRUE(time1 < time2);
}