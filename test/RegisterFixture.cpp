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
    Date date(2000,1,1);
    Time startTime(7,0,0);
    Time finishTime(8, 0, 0);
    std::string name="name";
    std::string description="description";

    Activity activity1(name, description, date, startTime, finishTime);
    r->insert(activity1);
    ASSERT_EQ(r->showQuantity(date),1);

    auto it = r->returnDay(date);
    ASSERT_EQ(it->second.getName(),name);
    ASSERT_EQ(it->second.getDescription(),description);
    ASSERT_EQ(it->second.getStartDay(),date);
    ASSERT_EQ(it->second.getStartTime(),startTime);
    ASSERT_EQ(it->second.getFinishTime(),finishTime);
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
    ASSERT_EQ(quantity,0);
    ASSERT_THROW(r->deleteDay(date2),std::invalid_argument);

    quantity = r->showQuantity(date1);
    ASSERT_EQ(quantity,2);
    r->deleteDay(date1);
    quantity = r->showQuantity(date1);
    ASSERT_EQ(quantity,0);
}

TEST_F(RegisterSuite,TestDeleteActivity) {
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
    ASSERT_EQ(quantity,0);
    ASSERT_THROW(r->deleteActivity(date2,name3),std::invalid_argument);

    quantity = r->showQuantity(date1);
    ASSERT_EQ(quantity,2);
    ASSERT_THROW(r->deleteActivity(date1,name3),std::invalid_argument);

    quantity = r->showQuantity(date1);
    ASSERT_EQ(quantity,2);
    r->deleteActivity(date1,name2);
    quantity = r->showQuantity(date1);
    ASSERT_EQ(quantity,1);
}

