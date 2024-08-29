//
// Created by marco on 03/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_TIME_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_TIME_H
#include <iostream>
#include <stdexcept>

class Time {
public:
    explicit Time(int h=0, int m=0, int s=0);

    // SETTER AND GETTER
    void setHour(const int& h);
    void setMinute(const int& m);
    void setSecond(const int& s);

    const int& getHour() const;
    const int& getMinute() const;
    const int& getSecond() const;

    // OPERATORS
    bool operator<(const Time& orig) const;
    bool operator==(const Time& orig) const;

private:
    int hour=0;
    int minute=0;
    int second=0;
};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_TIME_H
