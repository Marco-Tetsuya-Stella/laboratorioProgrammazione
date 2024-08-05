//
// Created by marco on 03/08/24.
//

#include "Activity.h"


Activity::Activity(const std::string &n, const std::string &d, const Date &sD, const Time &sT,
                   const Time &fT): name(n) , description(d) , startDay(sD), startTime(sT) ,
                                    finishTime(fT) {}



// getter and setter
const std::string &Activity::getName() const {
    return name;
}

void Activity::setName(const std::string &name) {
    Activity::name = name;
}

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

const Date &Activity::getStartDay() const {
    return startDay;
}

void Activity::setStartDay(const Date &startDay) {
    Activity::startDay = startDay;
}

const Time &Activity::getStartTime() const {
    return startTime;
}

void Activity::setStartTime(const Time &startTime) {
    Activity::startTime = startTime;
}

const Time &Activity::getFinishTime() const {
    return finishTime;
}

void Activity::setFinishTime(const Time &finishTime) {
    Activity::finishTime = finishTime;
}

//functions
void Activity::show() const{
    std::cout << "Name : " << name << std::endl << std::endl;
    std::cout << "Start : " << std::endl;
    startDay.show();
    startTime.show();
    std::cout<<std::endl;
    std::cout << "Finish : " << std::endl;
    finishTime.show();
    std::cout<<std::endl;
    std::cout << "Description : " << description << std::endl << std::endl;
}



