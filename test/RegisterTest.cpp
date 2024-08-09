#include "gtest/gtest.h"
#include "../Register.h"


TEST(Register,Insert) {
    Date date(2000,1,1);
    Date invalidDate(2013,45,-4);
    Time startTime(7,0,0);
    Time invalidStartTime(-120,700,99);
    Time finishTime(8, 0, 0);
    Time invalidFinishTime(24,60,-80);
    std::string name="name";
    std::string description="description";

    Register activities;
    std::string returnMessage="";

    Activity activity1(name, description, date, finishTime, startTime);
    returnMessage = activities.insert(activity1);
    ASSERT_EQ(returnMessage,"The start time value must be less than the end time value. Insertion failed");

    Activity activity2(name, description, date, startTime, finishTime);
    returnMessage = activities.insert(activity2);
    ASSERT_EQ(returnMessage,"Activity saved");

    Activity dateInvalidActivity(name,description,invalidDate,startTime,finishTime);
    returnMessage = activities.insert(dateInvalidActivity);
    ASSERT_EQ(returnMessage,"The value of day is invalid. Insertion failed");

    Activity startTimeInvalidActivity(name,description,date,invalidStartTime,finishTime);
    returnMessage = activities.insert(startTimeInvalidActivity);
    ASSERT_EQ(returnMessage,"The value of start time is invalid. Insertion failed");

    Activity finishTimeInvalidActivity(name,description,date,startTime,invalidFinishTime);
    returnMessage = activities.insert(finishTimeInvalidActivity);
    ASSERT_EQ(returnMessage,"The value of finish time is invalid. Insertion failed");
}

TEST(Register,ReturnDay) {
    Register activities;

    Date date1(2000,1,1);
    Date date2(2001,4,28);
    Time startTime(7,0,0);
    Time finishTime(8, 0, 0);
    std::string name="name";
    std::string description="description";

    Activity activity1(name,description,date1,startTime,finishTime);
    Activity activity2(name,description,date2,startTime,finishTime);
    activities.insert(activity1);
    activities.insert(activity2);
    auto it = activities.returnDay(date1);
    ASSERT_EQ(it->second.getName(),activity1.getName());
    ASSERT_EQ(it->second.getDescription(),activity1.getDescription());
    ASSERT_EQ(it->second.getStartDay(),activity1.getStartDay());
    ASSERT_EQ(it->second.getStartTime(),activity1.getStartTime());
    ASSERT_EQ(it->second.getFinishTime(),activity1.getFinishTime());

    auto it2 = activities.returnDay(date2);
    ASSERT_EQ(it2->second.getName(),activity2.getName());
    ASSERT_EQ(it2->second.getDescription(),activity2.getDescription());
    ASSERT_EQ(it2->second.getStartDay(),activity2.getStartDay());
    ASSERT_EQ(it2->second.getStartTime(),activity2.getStartTime());
    ASSERT_EQ(it2->second.getFinishTime(),activity2.getFinishTime());
}

TEST(Register,ShowQuantity) {
    Register activities;
    int quantity=0;

    Date date1(2000,1,1);
    Time startTime(7,0,0);
    Time finishTime(8, 0, 0);
    std::string name1="name1";
    std::string name2="name2";
    std::string description="description";

    Activity activity1(name1,description,date1,startTime,finishTime);
    Activity activity2(name2,description,date1,startTime,finishTime);

    quantity = activities.showQuantity(date1);
    ASSERT_EQ(quantity,0);
    activities.insert(activity1);
    quantity = activities.showQuantity(date1);
    ASSERT_EQ(quantity,1);
    activities.insert(activity2);
    quantity = activities.showQuantity(date1);
    ASSERT_EQ(quantity,2);
    activities.deleteDay(date1);
    quantity = activities.showQuantity(date1);
    ASSERT_EQ(quantity,0);
}

TEST(Register,DeleteDay) {
    Register activities;
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

    activities.insert(activity1);
    activities.insert(activity2);

    quantity = activities.showQuantity(date2);
    returnMessage = activities.deleteDay(date2);
    ASSERT_EQ(quantity,0);
    ASSERT_EQ(returnMessage,"There isn't saved activity on that day");

    quantity = activities.showQuantity(date1);
    returnMessage = activities.deleteDay(date1);
    ASSERT_EQ(quantity,2);
    ASSERT_EQ(returnMessage,"All activities of that day deleted");

    quantity = activities.showQuantity(date1);
    ASSERT_EQ(quantity,0);
}

TEST(Register,DeleteActivity) {
    Register activities;
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

    activities.insert(activity1);
    activities.insert(activity2);

    quantity = activities.showQuantity(date2);
    returnMessage = activities.deleteActivity(date2,name3);
    ASSERT_EQ(quantity,0);
    ASSERT_EQ(returnMessage,"There isn't saved activity on that day");

    quantity = activities.showQuantity(date1);
    returnMessage = activities.deleteActivity(date1,name3);
    ASSERT_EQ(quantity,2);
    ASSERT_EQ(returnMessage,"There isn't activity with that name");

    quantity = activities.showQuantity(date1);
    returnMessage = activities.deleteActivity(date1,name2);
    ASSERT_EQ(quantity,2);
    ASSERT_EQ(returnMessage,"Activity name2 deleted");

    quantity = activities.showQuantity(date1);
    ASSERT_EQ(quantity,1);
}







