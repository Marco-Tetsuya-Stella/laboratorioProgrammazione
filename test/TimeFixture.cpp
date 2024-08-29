#include "gtest/gtest.h"
#include "../Time.h"


class TimeSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        t = new Time;
    }

    virtual void TearDown() {
        delete t;
    }

    Time* t = nullptr;
};

TEST_F(TimeSuite,TestConstructor) {
    ASSERT_EQ(t->getHour(),0);
    ASSERT_EQ(t->getMinute(),0);
    ASSERT_EQ(t->getSecond(),0);
}

TEST_F(TimeSuite,TestSetHour) {
    ASSERT_EQ(t->getHour(),0);
    t->setHour(23);
    ASSERT_EQ(t->getHour(),23);

    ASSERT_THROW(t->setHour(24),std::invalid_argument);
    ASSERT_THROW(t->setHour(-10),std::invalid_argument);
}

TEST_F(TimeSuite,TestSetMinute) {
    ASSERT_EQ(t->getMinute(),0);
    t->setMinute(59);
    ASSERT_EQ(t->getMinute(),59);

    ASSERT_THROW(t->setMinute(60),std::invalid_argument);
    ASSERT_THROW(t->setMinute(-10),std::invalid_argument);
}

TEST_F(TimeSuite,TestSetSecond) {
    ASSERT_EQ(t->getSecond(),0);
    t->setSecond(59);
    ASSERT_EQ(t->getSecond(),59);

    ASSERT_THROW(t->setSecond(60),std::invalid_argument);
    ASSERT_THROW(t->setSecond(-10),std::invalid_argument);
}

TEST_F(TimeSuite,TestOperators) {
    t->setHour(1);
    t->setMinute(1);
    t->setSecond(1);

    Time t2(1,1,1);
    ASSERT_TRUE(*t == t2);
    ASSERT_FALSE(*t < t2);
    t2.setSecond(2);
    ASSERT_TRUE(*t < t2);
    t2.setSecond(1);
    t2.setMinute(2);
    ASSERT_TRUE(*t < t2);
    t2.setMinute(1);
    t2.setHour(2);
    ASSERT_TRUE(*t < t2);
}


