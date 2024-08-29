//
// Created by marco on 03/08/24.
//

#include "Register.h"

// FUNCTIONS
void Register::insert(Activity &a) {
    activities.insert({a.getStartDay(), a});
}

std::multimap<Date,Activity>::iterator Register::returnDay(Date &d) {

    std::multimap<Date,Activity>::iterator it = activities.find(d);

    return it;
}

int Register::showQuantity(Date &d) {
    int countedDayActivities = activities.count(d);
    return countedDayActivities;
}

void Register::deleteDay(Date &d) {
    std::string result = "";
    int countedDayActivities = activities.count(d);

    if(countedDayActivities > 0) {
        auto it = activities.find(d);
        activities.erase(it , std::next(it,countedDayActivities));
    }
    else
    {
        throw std::invalid_argument("There isn't saved activity on that day");
    }
}

void Register::deleteActivity(Date &d, const std::string &name) {

    std::multimap<Date,Activity>::iterator deleteElement;
    bool find = false;

    int countedDayActivities = activities.count(d);
    if(countedDayActivities > 0) {
        auto it = activities.find(d);

        for(auto start = it ; start != std::next(it,countedDayActivities) ; start++){
            if( start->second.getName() == name ) {
                deleteElement = start;
                find = true;
            }
        }

        if(find) {
            activities.erase(deleteElement);
        }
        else
        {
            throw std::invalid_argument("There isn't saved activity with that name");
        }
    }
    else
    {
        throw std::invalid_argument("There isn't saved activity on that day");
    }
}