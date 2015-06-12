#include "../include/field.h"
#include <iostream>
using namespace std;

field::field(){
   marked=0;
   travel_time=0;
   lift_counter=0;
   lift *l=NULL;
}

field::~field(){
  delete l;
  cout << ":)";
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
    if(!travel_time||(prev_time<travel_time))
        travel_time=prev_time;

    return travel_time;
}

int field::compute_from_the(field * a, lift *l){
    if(marked)
        return 0;

    int time = travel_time;
    int mod = travel_time%l->travel_period;
    if(mod){
        travel_time+=l->travel_period-mod;
    }
    if(!travel_time||time<travel_time){
        travel_time=time;
    }

    return travel_time;
}

