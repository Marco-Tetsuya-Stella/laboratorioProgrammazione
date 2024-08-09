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

std::multimap<Date,Activity>::iterator Register::returnDay(Date &d) {

    std::multimap<Date,Activity>::iterator it = activities.find(d);

    return it;
}

int Register::showQuantity(Date &d) {
    int countedDayActivities = activities.count(d);
    return countedDayActivities;
}

std::string Register::deleteDay(Date &d) {
    std::string result = "";
    int countedDayActivities = activities.count(d);

    if(countedDayActivities > 0) {
        auto it = activities.find(d);
        activities.erase(it , std::next(it,countedDayActivities));
        std::cout << " All activities of that day deleted " << std::endl;
        result = "All activities of that day deleted";
    }
    else
    {
        std::cout << " There isn't saved activity on that day " << std::endl;
        result = "There isn't saved activity on that day";
    }
    return result;
}

std::string Register::deleteActivity(Date &d, const std::string &name) {
    std::stringstream stringstreamResult;
    stringstreamResult.str("");
    std::multimap<Date,Activity>::iterator deleteElement;
    bool find = false;

    std::string result = "There isn't activity with that name";
    int countedDayActivities = activities.count(d);
    if(countedDayActivities > 0) {
        auto it = activities.find(d);

        for(auto start = it ; start != std::next(it,countedDayActivities) ; start++){
            if( start->second.getName() == name ){
                deleteElement = start;
                find = true;
            }
        }
    }
    else
    {
        std::cout << " There isn't saved activity on that day " << std::endl;
        result = "There isn't saved activity on that day";
    }

    if(find){
        activities.erase(deleteElement);
        std::cout << " Activity " << name << " deleted " << std::endl;
        stringstreamResult << " Activity " << name << " deleted ";
        result = stringstreamResult.str();

    }
    return result;
}