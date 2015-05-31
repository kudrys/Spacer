#include "field.h"

field::field(){
   marked=0;
   time_travel=0;
}

field::~field(){
}

/** updatuje time_travel, sprawdza czy field jest marked
 *
 * param: field a - pole skad przyszlismy
 * return: zwraca time lub zero gdy marked
 */

int field::compute_from(field a){

    if(marked)
        return 0;

    int time=0;
    if(a.height>=height){
       time=1;
    }else{
        time=height-a.height+1;
    }
    if(time_travel&&a.travel_time+time<time_travel){
        time_travel=a.travel_time+time;
    }
    return time;
}
