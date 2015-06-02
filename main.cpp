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
        int startx,starty,stopx,stopy;
        int time,period;
        cin>>startx>>starty>>stopx>>stopy;
        cin>>time>>period;
        m.add_lift(startx,starty,stopx,stopy,time,period);
    }
    m.load_map();
    m.draw();

//    m.f_tab[0][1].marked=1;
//    cout<<"compute:"<<m.f_tab[0][0].compute_from(&m.f_tab[0][1])<<"\n";
//    cout<<"compute:"<<m.f_tab[0][1].compute_from(&m.f_tab[0][0])<<"\n";
//    cout<<"compute:"<<m.f_tab[1][2].compute_from(&m.f_tab[1][1])<<"\n";
//    cout<<"compute:"<<m.f_tab[1][2].compute_from(&m.f_tab[3][5])<<"\n";
//    cout<<"compute:"<<m.f_tab[0][0].compute_from(&m.f_tab[0][1])<<"\n";
//    cout<<"compute:"<<m.f_tab[0][0].compute_from(&m.f_tab[0][1])<<"\n";
//    cout<<m.f_tab[3][5].height;
//    cout<<m.f_tab[1][2].height;
//








    cout<<"\n-----------------------\n";
    m.flood();
}


