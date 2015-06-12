#include "../include/mapa.h"
#include "../include/mapa.h"
#include "../include/field.h"
#include <iostream>
using namespace std;

mapa::mapa(int x, int y){
    this->x=x;
    this->y=y;
    f_tab = new field* [y];
    for (int i = 0; i < y; i++) {
        f_tab[i] = new field [x];
    }

	h.width=x;
	h.tabsize=1;
	h.heap_size=0;
	h.tab = new int [h.tabsize];

	h.map_tab=f_tab;
	h.x=x;
	h.y=y;
}

mapa::~mapa(){
    //cout << "map deleted";
}

void mapa::load_map() {
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>f_tab[i][j].height;
        }
    }
}

void mapa::flood(){
    int activex=travel_start_x;
    int activey=travel_start_y;

    field * active = &f_tab[activey][activex];

    while (activex!=travel_destination_x|| activey!=travel_destination_y){
        compute_routes(activex, activey);
        int temp=h.remove_first();

        activex=temp%h.width;
        activey=temp/h.width;
        active = &f_tab[activey][activex];
    }
    cout <<active->travel_time;
}


void mapa::compute_routes(int activex, int activey){
    f_tab[activey][activex].marked=1;

    compute_near(activex, activey);
    compute_lifts(activex, activey);
}

//przyspieszyc
void mapa::compute_near(int activex, int activey){
    field * active = &f_tab[activey][activex];
    field * temp;

    //tab_x-y[4]={left,right,up,down}
    int tab_x[4]={activex-1,activex+1,activex,activex};
    int tab_y[4]={activey,activey,activey-1,activey+1};

    for(int i=0;i<4;i++){
        int temp_x=tab_x[i];
        int temp_y=tab_y[i];
        if(0<=temp_x&&temp_x<x&&0<=temp_y&&temp_y<y){
            temp = &f_tab[temp_y][temp_x];
            if(temp->marked)
                continue;
            if(!temp->travel_time){
                temp->compute_from(active);
                h.add(temp_x,temp_y);
            }else
            temp->compute_from(active);
        }
    }
}

void mapa::compute_lifts(int activex, int activey){
    field * active = &f_tab[activey][activex];
    field * temp;
    lift * ltemp=active->l;

    for(int i=0; i<active->lift_counter; i++){
        int temp_x=ltemp->x_destination;
        int temp_y=ltemp->y_destination;

        temp=&f_tab[temp_y][temp_x];
        if(temp->marked)
            continue;
        if(!temp->travel_time){
            temp->compute_from_the(active, ltemp);
            h.add(temp_x, temp_y);
        }else
            temp->compute_from_the(active, ltemp);
    }
}

void mapa::add_lift(){

    int startx,starty,stopx,stopy;
    int time,period;
    cin>>startx>>starty>>stopx>>stopy;
    cin>>time>>period;

    f_tab[startx][starty].lift_counter++;

    lift temp;
    temp.next = f_tab[startx][starty].l;
    f_tab[startx][starty].l = &temp;

    lift *active = f_tab[startx][starty].l;
    active->time_travel=time;
    active->travel_period=period;
    active->x_destination=stopx;
    active->y_destination=stopy;
}


void mapa::draw(){
   for(int i=0;i<y;i++){
        cout<<"\n";
        for(int j=0;j<x;j++){
            cout<<f_tab[i][j].height;
        }
    }
}

void mapa::draw_times(){
   for(int i=0;i<y;i++){
        cout<<"\n";
        for(int j=0;j<x;j++){
            cout<<f_tab[i][j].travel_time<<" ";
            if(f_tab[i][j].travel_time<10)
                cout<<" ";
        }
    }cout<<"\n\n";
}

void mapa::draw_times(int a, int b){
   for(int i=0;i<y;i++){
        cout<<"\n";
        for(int j=0;j<x;j++){
            if(f_tab[i][j].marked){

                if(a==j&&b==i){
                    cout<<"[] ";
                }else{
                    cout << "-- ";
                }
                continue;
            }else{
                cout<<f_tab[i][j].travel_time<<" ";
                if(f_tab[i][j].travel_time<10)
                    cout<<" ";
            }
        }

    }cout<<"\n\n";
}
