//
// Created by marco on 03/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_ACTIVITY_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_ACTIVITY_H
#include <stdexcept>
#include "Date.h"
#include "Time.h"


class Activity {
public:
    explicit Activity(const std::string& n, const std::string& d, const Date& sD ,const Time& sT, const Time& fT);

    // GETTER AND SETTER
    const std::string &getName() const;
    void setName(const std::string &name);

    const std::string &getDescription() const;
    void setDescription(const std::string &description);

    const Date &getStartDay() const;
    void setStartDay(const Date &startDay);

    const Time &getStartTime() const;
    void setStartTime(const Time &startTime);

    const Time &getFinishTime() const;
    void setFinishTime(const Time &finishTime);

private:
    std::string name=" ";
    std::string description=" ";

    Date startDay;
    Time startTime;
    Time finishTime;
};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_ACTIVITY_H
