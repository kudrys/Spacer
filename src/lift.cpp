#include "../include/lift.h"
#include <iostream>
using namespace std;

lift::lift(int x,int y,int time,int period){
    x_destination=x;
    y_destination=y;
    time_travel=time;
    travel_period=period;
    next = this;
}

lift::lift(){
}

lift::~lift(){
    //dtor
}


//void lift::add_lift(){
//    lift* l = new lift();
//    l->next=next;
//    next = l;
//}

//void lift::delete_lift(){
//    next=next->next;
//}

