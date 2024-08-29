//
// Created by marco on 03/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_REGISTER_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_REGISTER_H
#include <iostream>
#include <map>
#include <stdexcept>
#include "Date.h"
#include "Activity.h"
#include <string>
#include <sstream>

class Register {
public:
    // FUNCTIONS
    void insert(Activity& a);
    std::multimap<Date,Activity>::iterator returnDay(Date& d);
    int showQuantity(Date& d);
    void deleteDay(Date& d);
    void deleteActivity(Date& d,const std::string& name);

private:
    std::multimap<Date,Activity> activities;
};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_REGISTER_H
