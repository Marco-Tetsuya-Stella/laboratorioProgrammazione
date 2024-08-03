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
    void insert(Activity& a);
    void showDay(Date& d)const;


private:
    std::multimap<Date,Activity> activities;
};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_REGISTER_H
