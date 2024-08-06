//
// Created by marco on 03/08/24.
//

#include "Register.h"

//functions
std::string Register::insert(Activity &a) {
    std::string returnMessage = " ";

    if(a.getStartDay().getYear()==-1 or a.getStartDay().getMonth()==-1 or a.getStartDay().getDay()==-1) {
        std::cout << " The value of day is invalid. Insertion failed " << std::endl;
        returnMessage = "The value of day is invalid. Insertion failed";
    }
    else
    {
        if(a.getStartTime().getHour() == -1 or a.getStartTime().getMinute() == -1 or a.getStartTime().getSecond() == -1) {
            std::cout << " The value of start time is invalid. Insertion failed " << std::endl;
            returnMessage = "The value of start time is invalid. Insertion failed";
        }
        else
        {
            if(a.getFinishTime().getHour() == -1 or a.getFinishTime().getMinute() == -1 or a.getFinishTime().getSecond() == -1) {
                std::cout << " The value of finish time is invalid. Insertion failed " << std::endl;
                returnMessage = "The value of finish time is invalid. Insertion failed";
            }
            else
            {
                if(a.getStartTime() < a.getFinishTime()) {
                    activities.insert({a.getStartDay(), a});
                    std::cout << " Activity saved " << std::endl;
                    returnMessage = "Activity saved";
                }
                else
                {
                    std::cout << " The start time value must be less than the end time value. Insertion failed " << std::endl;
                    returnMessage = "The start time value must be less than the end time value. Insertion failed";
                }
            }
        }
    }
    return returnMessage;
}

void Register::showDay(Date &d) const {

    auto it = activities.find(d);
    if (it == activities.end())
        std::cout << " Didn't find the day " << std::endl;
    else {
        int countedDayActivities = activities.count(d);
        for (auto start = it; start != std::next(it, countedDayActivities); start++) {
            start->second.show();
        }
    }
}

std::multimap<Date,Activity>::iterator Register::returnDay(Date &d) {

    std::multimap<Date,Activity>::iterator it = activities.find(d);

    return it;
}

int Register::showQuantity(Date &d) {
    int countedDayActivities = activities.count(d);
    return countedDayActivities;
}



