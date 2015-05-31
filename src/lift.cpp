#include "lift.h"
#include <iostream>
using namespace std;

lift::lift(x,y,time,period){
    x_destination=x;
    y_destination=y;
    time_travel=time;
    travel_period=period;
}

lift::~lift(){
    //dtor
}


