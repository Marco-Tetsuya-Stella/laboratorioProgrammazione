//
// Created by marco on 03/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_DATE_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_DATE_H

#include <iostream>
#include <stdexcept>

class Date {
public:
    explicit Date(int y=2024,int m=1,int d=1);

    // SETTER AND GETTER
    void setYear(const int& y);
    void setMonth(const int& m);
    void setDay(const int& d);

    const int& getYear() const;
    const int& getMonth() const;
    const int& getDay() const;

    // OPERATORS
    bool operator==(const Date& orig) const;
    bool operator<(const Date& orig) const;

private:
    // PRIVATE FUNCTIONS
    void setThirtyDay(int d);
    void setThirtyOneDay(int d);
    void setFebruaryDay(int d);

    int year;
    int month;
    int day;
};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_DATE_H
