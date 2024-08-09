#include "gtest/gtest.h"
#include "../Activity.h"

TEST(Activity,Constructor) {
    Date date(2024,8,9);
    Time time1(20,17,14);
    Time time2(21,23,45);
    std::string name="Nome";
    std::string description="Description";

    Activity activity1(name,description,date,time1,time2);

    ASSERT_EQ(activity1.getName(),"Nome");
    ASSERT_EQ(activity1.getDescription(),"Description");
    ASSERT_EQ(activity1.getStartDay().getYear(),2024);
    ASSERT_EQ(activity1.getStartDay().getMonth(),8);
    ASSERT_EQ(activity1.getStartDay().getDay(),9);
    ASSERT_EQ(activity1.getStartTime().getHour(),20);
    ASSERT_EQ(activity1.getStartTime().getMinute(),17);
    ASSERT_EQ(activity1.getStartTime().getSecond(),14);
    ASSERT_EQ(activity1.getFinishTime().getHour(),21);
    ASSERT_EQ(activity1.getFinishTime().getMinute(),23);
    ASSERT_EQ(activity1.getFinishTime().getSecond(),45);
}






