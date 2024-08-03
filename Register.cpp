//
// Created by marco on 03/08/24.
//

#include "Register.h"



void Register::insert(Activity &a) {
    activities.insert({a.getStartDay(),a});
}





