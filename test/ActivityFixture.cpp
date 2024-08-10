#include "gtest/gtest.h"
#include "../Activity.h"

class ActivitySuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        Date date(2024,8,9);
        Time time1(20,17,14);
        Time time2(21,23,45);
        std::string name="Nome";
        std::string description="Description";
        a = new Activity(name,description,date,time1,time2);
    }

    virtual void TearDown() {
        delete a;
    }

    Activity* a = nullptr;
};

TEST_F(ActivitySuite,Constructor) {
    ASSERT_EQ(a->getName(),"Nome");
    ASSERT_EQ(a->getDescription(),"Description");
    ASSERT_EQ(a->getStartDay().getYear(),2024);
    ASSERT_EQ(a->getStartDay().getMonth(),8);
    ASSERT_EQ(a->getStartDay().getDay(),9);
    ASSERT_EQ(a->getStartTime().getHour(),20);
    ASSERT_EQ(a->getStartTime().getMinute(),17);
    ASSERT_EQ(a->getStartTime().getSecond(),14);
    ASSERT_EQ(a->getFinishTime().getHour(),21);
    ASSERT_EQ(a->getFinishTime().getMinute(),23);
    ASSERT_EQ(a->getFinishTime().getSecond(),45);
}




