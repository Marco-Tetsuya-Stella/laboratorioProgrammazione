//
// Created by marco on 03/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_TIME_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_TIME_H
#include <iostream>

class Time {
public:

    explicit Time(int h=0, int m=0, int s=0);
    //getter and setter
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    //operator
    bool operator<(const Time& orig) const;
    bool operator==(const Time& orig) const;

private:
    int hour=0;
    int minute=0;
    int second=0;

};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_TIME_H
