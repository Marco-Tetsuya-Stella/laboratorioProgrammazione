#include "gtest/gtest.h"
#include "../Register.h"

class RegisterSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        r = new Register;
    }

    virtual void TearDown() {
        delete r;
    }

    Register* r = nullptr;
};

TEST_F(RegisterSuite,TestInsert) {
    Date date1(2000,1,1);
    Date invalidDate(2013,45,-4);
    Time startTime(7,0,0);
    Time invalidStartTime(-120,700,99);
    Time finishTime(8, 0, 0);
    Time invalidFinishTime(24,60,-80);
    std::string name1="name1";
    std::string description1="description1";
    std::string returnMessage="";


    Activity timeInvalidActivity(name1, description1, date1, finishTime, startTime);
    returnMessage = r->insert(timeInvalidActivity);
    ASSERT_EQ(returnMessage,"The start time value must be less than the end time value. Insertion failed");

    Activity activity1(name1, description1, date1, startTime, finishTime);
    returnMessage = r->insert(activity1);
    ASSERT_EQ(returnMessage,"Activity saved");

    Activity dateInvalidActivity(name1,description1,invalidDate,startTime,finishTime);
    returnMessage = r->insert(dateInvalidActivity);
    ASSERT_EQ(returnMessage,"The value of day is invalid. Insertion failed");

    Activity startTimeInvalidActivity(name1,description1,date1,invalidStartTime,finishTime);
    returnMessage = r->insert(startTimeInvalidActivity);
    ASSERT_EQ(returnMessage,"The value of start time is invalid. Insertion failed");

    Activity finishTimeInvalidActivity(name1,description1,date1,startTime,invalidFinishTime);
    returnMessage = r->insert(finishTimeInvalidActivity);
    ASSERT_EQ(returnMessage,"The value of finish time is invalid. Insertion failed");
}

TEST_F(RegisterSuite,TestReturnDay) {
    Date date1(2001, 1, 1);
    Date date2(2002, 4, 28);
    Time startTime1(7,0,0);
    Time finishTime1(8, 0, 0);
    Time startTime2(7, 30, 0);
    Time finishTime2(8, 30, 0);
    std::string name1="name1";
    std::string description1="description1";
    std::string name2="name2";
    std::string description2="description2";

    Activity activity2(name1, description1, date1, startTime1, finishTime1);
    Activity activity3(name2, description2, date2, startTime2, finishTime2);

    r->insert(activity2);
    r->insert(activity3);
    auto it = r->returnDay(date1);
    ASSERT_EQ(it->second.getName(),activity2.getName());
    ASSERT_EQ(it->second.getDescription(),activity2.getDescription());
    ASSERT_EQ(it->second.getStartDay(),activity2.getStartDay());
    ASSERT_EQ(it->second.getStartTime(),activity2.getStartTime());
    ASSERT_EQ(it->second.getFinishTime(),activity2.getFinishTime());

    auto it2 = r->returnDay(date2);
    ASSERT_EQ(it2->second.getName(),activity3.getName());
    ASSERT_EQ(it2->second.getDescription(),activity3.getDescription());
    ASSERT_EQ(it2->second.getStartDay(),activity3.getStartDay());
    ASSERT_EQ(it2->second.getStartTime(),activity3.getStartTime());
    ASSERT_EQ(it2->second.getFinishTime(),activity3.getFinishTime());
}

TEST_F(RegisterSuite,TestShowQuantity) {
    int quantity=0;

    Date date4(2000,1,1);
    Time startTime(7,0,0);
    Time finishTime(8, 0, 0);
    std::string name1="name1";
    std::string name2="name2";
    std::string description="description";

    Activity activity1(name1,description,date4,startTime,finishTime);
    Activity activity2(name2,description,date4,startTime,finishTime);

    quantity = r->showQuantity(date4);
    ASSERT_EQ(quantity,0);
    r->insert(activity1);
    quantity = r->showQuantity(date4);
    ASSERT_EQ(quantity,1);
    r->insert(activity2);
    quantity = r->showQuantity(date4);
    ASSERT_EQ(quantity,2);
    r->deleteDay(date4);
    quantity = r->showQuantity(date4);
    ASSERT_EQ(quantity,0);
}

TEST_F(RegisterSuite,TestDeleteDay) {
    std::string returnMessage="";
    int quantity=0;

    Date date1(2000,1,1);
    Date date2(1000,1,1);
    Time startTime(7,0,0);
    Time finishTime(8, 0, 0);
    std::string name1="name1";
    std::string name2="name2";
    std::string description="description";

    Activity activity1(name1,description,date1,startTime,finishTime);
    Activity activity2(name2,description,date1,startTime,finishTime);

    r->insert(activity1);
    r->insert(activity2);

    quantity = r->showQuantity(date2);
    returnMessage = r->deleteDay(date2);
    ASSERT_EQ(quantity,0);
    ASSERT_EQ(returnMessage,"There isn't saved activity on that day");

    quantity = r->showQuantity(date1);
    returnMessage = r->deleteDay(date1);
    ASSERT_EQ(quantity,2);
    ASSERT_EQ(returnMessage,"All activities of that day deleted");

    quantity = r->showQuantity(date1);
    ASSERT_EQ(quantity,0);
}

TEST_F(RegisterSuite,TestDeleteActivity) {
    std::string returnMessage="";
    int quantity=0;

    Date date1(2000,1,1);
    Date date2(1000,1,1);
    Time startTime(7,0,0);
    Time finishTime(8, 0, 0);
    std::string name1="name1";
    std::string name2="name2";
    std::string name3="name3";
    std::string description="description";

    Activity activity1(name1,description,date1,startTime,finishTime);
    Activity activity2(name2,description,date1,startTime,finishTime);

    r->insert(activity1);
    r->insert(activity2);

    quantity = r->showQuantity(date2);
    returnMessage = r->deleteActivity(date2,name3);
    ASSERT_EQ(quantity,0);
    ASSERT_EQ(returnMessage,"There isn't saved activity on that day");

    quantity = r->showQuantity(date1);
    returnMessage = r->deleteActivity(date1,name3);
    ASSERT_EQ(quantity,2);
    ASSERT_EQ(returnMessage,"There isn't activity with that name");

    quantity = r->showQuantity(date1);
    returnMessage = r->deleteActivity(date1,name2);
    ASSERT_EQ(quantity,2);
    ASSERT_EQ(returnMessage,"Activity name2 deleted");

    quantity = r->showQuantity(date1);
    ASSERT_EQ(quantity,1);
}

