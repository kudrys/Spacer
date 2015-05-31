#include <iostream>
#include "mapa.h"
using namespace std;

int main(){
    int x;
    int y;
    int travel_start_x;
    int travel_start_y;
    int travel_destination_x;
    int travel_destination_y;
    int lift_counter;
    cin>>x;
    cin>>y;
    mapa m(x,y);
    cin>>travel_start_x;
    cin>>travel_start_y;
    cin>>travel_destination_x;
    cin>>travel_destination_y;
    cin>>lift_counter;

    for(int i=0;i<lift_counter;i++){
        int startx,starty,stopx,stopy;
        int time,period;
        cin>>startx>>starty>>stopx>>stopy;
        cin>>time>>period;
        m.add_lift(startx,starty,stopx,stopy,time,period);
    }
    cout<<"kek";
    m.load_map();
    m.draw();
}


