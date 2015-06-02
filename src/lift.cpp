#include "../include/lift.h"
#include <iostream>
using namespace std;

lift::lift(int x,int y,int time,int period){
    x_destination=x;
    y_destination=y;
    time_travel=time;
    travel_period=period;
}

lift::~lift(){
    //dtor
}


