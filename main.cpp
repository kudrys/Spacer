#include <iostream>
#include "include/mapa.h"
using namespace std;

int main(){

    int x;
    int y;
    cin>>x;
    cin>>y;
    mapa m(x,y);
    cin>>m.travel_start_x;
    cin>>m.travel_start_y;
    cin>>m.travel_destination_x;
    cin>>m.travel_destination_y;
    cin>>m.lift_counter;

    for(int i=0;i<m.lift_counter;i++){

        m.add_lift();
    }
    m.load_map();
    m.flood();
    //delete &m;
}


