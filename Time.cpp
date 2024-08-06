//
// Created by marco on 03/08/24.
//

#include "Time.h"

Time::Time(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}


//getter and setter
void Time::setHour(int h) {
    if( h<0 or h>24 ) {
        std::cout << "Hour is invalid a default parameter will be applied " << std::endl;
        hour=-1;
    }
    else
    {
        hour=h;
    }
}

void Time::setMinute(int m) {
    if( m<0 or m>60 ) {
        std::cout << "Minute is invalid a default parameter will be applied " << std::endl;
        minute=-1;
    }
    else
    {
        minute=m;
    }
}

void Time::setSecond(int s) {
    if( s<0 or s>60 ) {
        std::cout << "Second is invalid a default parameter will be applied " << std::endl;
        second=-1;
    }
    else
    {
        second=s;
    }
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

//operators
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




//functions
void Time::show() const{
    std::cout << "Hour : " << hour << std::endl
              << "Minute : " << minute << std::endl
              << "Second : " << second << std::endl;
}







