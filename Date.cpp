//
// Created by marco on 03/08/24.
//

#include "Date.h"


Date::Date(int y, int m, int d) {
    setYear(y);
    setMonth(m);
    setDay(d);
}

void Date::setYear(int y) {
    if(y<0) {
        std::cout << " Year is invalid a default parameter will be applied " << std::endl;
        year = -1;
    }
    else
    {
        year=y;
    }
}

void Date::setMonth(int m) {
    if(m<1 or m>12 or year==-1) {
        std::cout << " Month is invalid a default parameter will be applied " << std::endl;
        month=-1;
    }
    else
    {
        month=m;
    }
}

void Date::setDay(int d) {
    if( d<1 or d>31){
        std::cout << " Day is invalid a default parameter will be applied " << std::endl;
        day = -1;
    }
    else
    {
        switch (month) {
            case -1:
                std::cout<<" Month is invalid a default parameter for day will be applied " << std::endl;
                day=-1;
                break;
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

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

//operators

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

//functions
void Date::show() const {
    std::cout << "Year : " << year << std::endl
              << "Month : " << month << std::endl
              << "Day : " << day <<std::endl;
}

//private functions
void Date::setThirtyOneDay(int d) {
    day=d;
}

void Date::setThirtyDay(int d) {
    if(d<=30) {
        day = d;
    }
    else
    {
        std::cout << " Day is invalid a default parameter will be applied " << std::endl;
        day=-1;
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
            std::cout << " Day is invalid a default parameter will be applied " << std::endl;
            day=-1;
        }
    }
    else
    {
        if(d<=28) {
            day=d;
        }
        else
        {
            std::cout << " Day is invalid a default parameter will be applied " << std::endl;
            day=-1;
        }
    }
}











