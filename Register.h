//
// Created by marco on 03/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_REGISTER_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_REGISTER_H
#include <iostream>
#include <map>
#include "Date.h"
#include "Activity.h"

class Register {
public:
    //functions
    std::string insert(Activity& a);
    void showDay(Date& d)const;
    std::multimap<Date,Activity>::iterator returnDay(Date& d );
    int showQuantity(Date& d);


private:
    std::multimap<Date,Activity> activities;
};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_REGISTER_H
