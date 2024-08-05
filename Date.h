//
// Created by marco on 03/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_DATE_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_DATE_H

#include <iostream>

class Date {

public:
    explicit Date(int y=0,int m=0,int d=0);

    //setter and getter
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);


    int getYear() const;
    int getMonth() const;
    int getDay() const;

    //operators
    bool operator==(const Date& orig) const;
    bool operator<(const Date& orig) const;

    //functions
    void show() const;

private:

    void setThirtyDay(int d);
    void setThirtyOneDay(int d);
    void setFebruaryDay(int d);


    int year=0;
    int month=0;
    int day=0;
};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_DATE_H
