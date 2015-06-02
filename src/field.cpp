#include "../include/field.h"

field::field(){
   marked=0;
   travel_time=0;
}

field::~field(){
}

/** updatuje travel_time, sprawdza czy field jest marked
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
    if(travel_time&&a.travel_time+time<travel_time){
        travel_time=a.travel_time+time;
    }
    return time;
}
