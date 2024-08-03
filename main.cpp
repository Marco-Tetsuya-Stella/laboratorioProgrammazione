#include <iostream>

#include "Date.h"
#include "Activity.h"
#include "Register.h"


int main() {

    Date d1(2013,3,10);

    Time t1(1,1,10);
    Time t2(2,2,20);

    std::string Nome="Nome";
    std::string Descrizione="Descrizione";
    std::string Nome2="Nome2";


    Activity activity(Nome,Descrizione,d1,d1,t1,t2);
    Activity activity2(Nome2, Descrizione,d1,d1,t1,t2);

    Register activities;
    activities.insert(activity);
    activities.insert(activity2);
    activities.showDay(d1);


}
