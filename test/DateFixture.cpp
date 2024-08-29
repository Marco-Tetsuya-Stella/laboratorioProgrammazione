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
    ASSERT_EQ(d->getYear(),2024);
    ASSERT_EQ(d->getMonth(),1);
    ASSERT_EQ(d->getDay(),1);
}

TEST_F(DateSuite,TestSetYear) {
    d->setYear(2024);
    ASSERT_EQ(d->getYear(),2024);
    ASSERT_THROW(d->setYear(-2024),std::invalid_argument);
}

TEST_F(DateSuite,TestSetMonth) {

    d->setMonth(12);
    ASSERT_EQ(d->getMonth(),12);

    ASSERT_THROW(d->setMonth(13),std::invalid_argument);
    ASSERT_THROW(d->setMonth(0),std::invalid_argument);
    ASSERT_THROW(d->setMonth(-12),std::invalid_argument);
}

TEST_F(DateSuite,TestSetDay) {
    d->setYear(2023);
    d->setMonth(1);
    d->setDay(31);
    ASSERT_EQ(d->getDay(),31);

    ASSERT_THROW(d->setDay(32),std::invalid_argument);
    ASSERT_THROW(d->setDay(0),std::invalid_argument);
    ASSERT_THROW(d->setDay(-31),std::invalid_argument);

    d->setMonth(4);
    ASSERT_THROW(d->setDay(31),std::invalid_argument);
    d->setDay(30);
    ASSERT_EQ(d->getDay(),30);

    d->setMonth(2);
    ASSERT_THROW(d->setDay(29),std::invalid_argument);
    d->setYear(2024);
    d->setDay(29);
    ASSERT_EQ(d->getDay(),29);

    d->setYear(1900);
    ASSERT_THROW(d->setDay(29),std::invalid_argument);
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




