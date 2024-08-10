#include "gtest/gtest.h"
#include "../Date.h"

class DateSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        d = new Date;
    }

    virtual void TearDown() {
        delete d;
    }

    Date* d = nullptr;
};

TEST_F(DateSuite,TestConstructor) {
    ASSERT_EQ(d->getYear(),0);
    ASSERT_EQ(d->getMonth(),1);
    ASSERT_EQ(d->getDay(),1);
}

TEST_F(DateSuite,TestSetYear) {
    d->setYear(2024);
    ASSERT_EQ(d->getYear(),2024);
    d->setYear(-2024);
    ASSERT_EQ(d->getYear(),-1);
}

TEST_F(DateSuite,TestSetMonth) {
    d->setYear(2024);
    d->setMonth(12);
    ASSERT_EQ(d->getMonth(),12);
    d->setMonth(13);
    ASSERT_EQ(d->getMonth(),-1);
    d->setMonth(0);
    ASSERT_EQ(d->getMonth(),-1);
    d->setMonth(-12);
    ASSERT_EQ(d->getMonth(),-1);
}

TEST_F(DateSuite,TestSetDay) {
    d->setYear(2023);
    d->setMonth(1);
    d->setDay(31);
    ASSERT_EQ(d->getDay(),31);
    d->setDay(32);
    ASSERT_EQ(d->getDay(),-1);
    d->setDay(0);
    ASSERT_EQ(d->getDay(),-1);
    d->setDay(-31);
    ASSERT_EQ(d->getDay(),-1);

    d->setMonth(4);
    d->setDay(31);
    ASSERT_EQ(d->getDay(),-1);
    d->setDay(30);
    ASSERT_EQ(d->getDay(),30);

    d->setMonth(2);
    d->setDay(29);
    ASSERT_EQ(d->getDay(),-1);
    d->setYear(2024);
    d->setDay(29);
    ASSERT_EQ(d->getDay(),29);

    d->setYear(1900);
    d->setDay(29);
    ASSERT_EQ(d->getDay(),-1);
}

TEST_F(DateSuite,TestOperators) {
    d->setYear(1);
    d->setMonth(1);
    d->setDay(1);

    Date d2(1,1,1);

    ASSERT_FALSE(*d < d2);
    ASSERT_TRUE(*d == d2);
    d2.setDay(2);
    ASSERT_TRUE(*d < d2);
    d2.setDay(1);
    d2.setMonth(2);
    ASSERT_TRUE(*d < d2);
    d2.setMonth(1);
    d2.setYear(2);
    ASSERT_TRUE(*d < d2);
}




