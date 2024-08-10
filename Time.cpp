//
// Created by marco on 03/08/24.
//

#include "Time.h"

Time::Time(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}


// SETTER AND GETTER
void Time::setHour(const int& h) {
    if( h<0 or h>23 ) {
        std::cout << " Hour is invalid a default parameter will be applied " << std::endl;
        hour=-1;
    }
    else
    {
        hour=h;
    }
}

void Time::setMinute(const int& m) {
    if( m<0 or m>59 ) {
        std::cout << " Minute is invalid a default parameter will be applied " << std::endl;
        minute=-1;
    }
    else
    {
        minute=m;
    }
}

void Time::setSecond(const int& s) {
    if( s<0 or s>59 ) {
        std::cout << " Second is invalid a default parameter will be applied " << std::endl;
        second=-1;
    }
    else
    {
        second=s;
    }
}

const int& Time::getHour() const {
    return hour;
}

const int& Time::getMinute() const {
    return minute;
}

const int& Time::getSecond() const {
    return second;
}

// OPERATORS
bool Time::operator<(const Time &orig) const {
    bool result=false;
    if(hour < orig.hour ){
        result=true;
    }
    else
    {
        if(hour == orig.hour){
            if(minute < orig.minute){
                result=true;
            }
            else
            {
                if(minute == orig.minute){
                    if(second < orig.second){
                        result= true;
                    }
                }
            }
        }
    }
    return result;
}

bool Time::operator==(const Time &orig) const {
    return hour == orig.hour  and  minute == orig.minute  and  second == orig.second;
}






