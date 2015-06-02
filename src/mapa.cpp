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
}

mapa::~mapa(){
    //dtor
}

void mapa::load_map() {
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            cin>>f_tab[i][j].height;
        }
    }
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
            if(a==i&&b==j){
                cout<<"[] ";
            }else{
            cout<<f_tab[i][j].travel_time<<" ";
            if(f_tab[i][j].travel_time<10)
                cout<<" ";
            }
        }
    }cout<<"\n\n";
}

int mapa::time_count(field *startA,field *metaB){

    if(startA->height >= metaB->height){
        return 1;
    }else{
        return metaB->height-startA->height+1;
    }
}

void mapa::flood(){
    int activex=travel_start_x;
    int activey=travel_start_y;

    field * active = &f_tab[activex][activey];


    while (active != &f_tab[travel_destination_y][travel_destination_x]){

        int k;
        cin>>k;
        draw_times(activex,activey);


        activex=travel_start_x;
        activey=travel_start_y;

        active = &f_tab[activey][activex];
        active->marked=1;
        field * temp;

        int temp_time=-1;
        //tab_x-y[4]={left,right,up,down}
        int tab_x[4]={activex-1,activex+1,activex,activex};
        int tab_y[4]={activey,activey,activey-1,activey+1};

        for(int i=0;i<4;i++){
        cout<<"\n-"<<i<<"-\n";
            int temp_x=tab_x[i];
            int temp_y=tab_y[i];
            if(0<=temp_x&&temp_x<x&&0<=temp_y&&temp_y<y){
                temp = &f_tab[temp_y][temp_x];
                if(temp->marked)
                    continue;
                //temp->travel_time=time_count(active,temp);
                int shortest_time=temp->compute_from(active);
                if(shortest_time&&(shortest_time<temp_time||temp_time==-1)){
                    travel_start_x=temp_x;
                    travel_start_y=temp_y;
                }
            }else{
                continue;
            }
        }
    }
}

































void mapa::add_lift(int, int, int, int, int, int){
}
