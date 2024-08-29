#include "gtest/gtest.h"
#include "../Date.h"

TEST(Date,Constructor) {
    Date date(10,10,10);
    ASSERT_EQ(date.getYear(),10);
    ASSERT_EQ(date.getMonth(),10);
    ASSERT_EQ(date.getDay(),10);

    ASSERT_THROW(date.setYear(-12),std::invalid_argument);

    Date date1(2004,2,29);
    ASSERT_EQ(date1.getYear(),2004);
    ASSERT_EQ(date1.getMonth(),2);
    ASSERT_EQ(date1.getDay(),29);


    ASSERT_THROW(Date date2(2003,2,29),std::invalid_argument);
    ASSERT_THROW(Date date3(2100,2,29),std::invalid_argument);

    Date date4(01,01,01);
    ASSERT_EQ(date4.getYear(),01);
    ASSERT_EQ(date4.getMonth(),01);
    ASSERT_EQ(date4.getDay(),01);

    ASSERT_THROW(Date date5(0,0,0),std::invalid_argument);

    Date date6(0);
    ASSERT_EQ(date6.getYear(),0);
    ASSERT_EQ(date6.getMonth(),1);
    ASSERT_EQ(date6.getDay(),1);

    Date date7;
    ASSERT_EQ(date7.getYear(),2024);
    ASSERT_EQ(date7.getMonth(),1);
    ASSERT_EQ(date7.getDay(),1);

}

TEST(Date,Operators) {
    Date date1(2017,4,26);
    Date date2(2017,4,26);
    ASSERT_FALSE(date1 < date2);
    ASSERT_TRUE(date1 == date2);
    date2.setYear(2016);
    ASSERT_FALSE(date1 == date2);
    date2.setYear(2018);
    ASSERT_TRUE(date1 < date2);
    date2.setYear(2017);
    date2.setMonth(5);
    ASSERT_TRUE(date1 < date2);
    date2.setMonth(4);
    date2.setDay(27);
    ASSERT_TRUE(date1 < date2);
}
