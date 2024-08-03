//
// Created by marco on 03/08/24.
//

#include "Time.h"

Time::Time(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    if( h<0 or h>24 ) {
        std::cout << "Hour is invalid a default parameter will be applied " << std::endl;
        hour=0;
    }
    else
    {
        hour=h;
    }
}

void Time::setMinute(int m) {
    if( m<0 or m>60 ) {
        std::cout << "Minute is invalid a default parameter will be applied " << std::endl;
        minute=0;
    }
    else
    {
        minute=m;
    }
}

void Time::setSecond(int s) {
    if( s<0 or s>60 ) {
        std::cout << "Second is invalid a default parameter will be applied " << std::endl;
        second=0;
    }
    else
    {
        second=s;
    }
}









