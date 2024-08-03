//
// Created by marco on 03/08/24.
//

#include "Register.h"

//functions
void Register::insert(Activity &a) {
    if(a.getStartDay().getYear()==-1 or a.getStartDay().getMonth()==-1 or a.getStartDay().getDay()==-1)
        std::cout<<" The value of start day is invalid. Insertion failed "<<std::endl;
    else
        activities.insert({a.getStartDay(),a});
}

void Register::showDay(Date &d) const {

    auto it = activities.find(d);
    if (it == activities.end())
        std::cout << "Didn't find the day" << std::endl;
    else {
        int countedDayActivities = activities.count(d);
        for (auto start = it; start != std::next(it, countedDayActivities); start++) {
            start->second.show();
        }
    }
}



