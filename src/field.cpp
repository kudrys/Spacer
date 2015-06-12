#include "../include/field.h"
#include <iostream>
using namespace std;

field::field(){
   marked=0;
   travel_time=0;
   lift *l;
}

field::~field(){
}

/** updatuje travel_time, sprawdza czy field jest marked
 *
 * param: field a - pole skad przyszlismy
 * return: zwraca time lub zero gdy marked
 */

int field::compute_from(field *a){
    if(marked)
        return 0;

    int time=1;
    if(a->height<height){
        time+=height-a->height;
    }
    int prev_time=a->travel_time+time;
    if(!travel_time||(travel_time&&prev_time<travel_time))
        travel_time=prev_time;

    return travel_time;
}


void field::add_lift(){
    l->add_lift();
}
