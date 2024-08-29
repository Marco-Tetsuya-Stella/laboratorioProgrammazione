//
// Created by marco on 03/08/24.
//

#include "Date.h"


Date::Date(int y, int m, int d) {
    setYear(y);
    setMonth(m);
    setDay(d);
}


// SETTER AND GETTER
void Date::setYear(const int& y) {
    if(y<0) {
        throw std::invalid_argument("The year value is invalid");
    }
    else
    {
        year=y;
    }
}

void Date::setMonth(const int& m) {
    if( m<1 or m>12 ) {
        throw std::invalid_argument("The month value is invalid");
    }
    else
    {
        month=m;
    }
}

void Date::setDay(const int& d) {
    if( d<1 or d>31){
        throw std::invalid_argument("The day value is invalid");
    }
    else
    {
        switch (month) {
            case 1:
                setThirtyOneDay(d);
                break;

            case 2:
                setFebruaryDay(d);
                break;

            case 3:
                setThirtyOneDay(d);
                break;

            case 4:
                setThirtyDay(d);
                break;

            case 5:
                setThirtyOneDay(d);
                break;

            case 6:
                setThirtyDay(d);
                break;

            case 7:
                setThirtyOneDay(d);
                break;

            case 8:
                setThirtyOneDay(d);
                break;

            case 9:
                setThirtyDay(d);
                break;

            case 10:
                setThirtyOneDay(d);
                break;

            case 11:
                setThirtyDay(d);
                break;

            case 12:
                setThirtyOneDay(d);
                break;
        }
    }
}

const int& Date::getYear() const {
    return year;
}

const int& Date::getMonth() const {
    return month;
}

const int& Date::getDay() const {
    return day;
}

// OPERATORS
bool Date::operator==(const Date &orig) const {
    return year==orig.year && month==orig.month && day==orig.day;
}

bool Date::operator<(const Date &orig) const {
    bool result=false;
    if(year < orig.year ){
        result=true;
    }
    else
    {
        if(year == orig.year){
            if(month < orig.month){
                result=true;
            }
            else
            {
                if(month == orig.month){
                    if(day < orig.day){
                        result= true;
                    }
                }
            }
        }
    }
    return result;
}

// PRIVATE FUNCTIONS
void Date::setThirtyOneDay(int d) {
    day=d;
}

void Date::setThirtyDay(int d) {
    if(d<=30) {
        day = d;
    }
    else
    {
        throw std::invalid_argument("The day value is invalid");
    }
}

void Date::setFebruaryDay(int d) {

    bool leapYear=false;
    bool secular=false;

    if( (year%100)==0 )
        secular= true;

    if( ( secular and (year%400)==0 )  or ( !secular and (year%4)==0 ) ) {
        leapYear= true;
    }

    if(leapYear){
        if(d<=29) {
            day=d;
        }
        else
        {
            throw std::invalid_argument("The day value is invalid");
        }
    }
    else
    {
        if(d<=28) {
            day=d;
        }
        else
        {
            throw std::invalid_argument("The day value is invalid");
        }
    }
}











