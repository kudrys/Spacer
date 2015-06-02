#include "mapa.h"
#include "field.h"
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

int mapa::time_count(field startA,field metaB){
    if(startA.height>=metaB.height){
        return 1;
    }else{
        return metaB.height-startA.height+1;
    }
}



void mapa::flood(){

    int activex=travel_start_x;
    int activey=travel_start_y;

    field * active=f_tab[activex][activey];
    field * temp;
    while (active!=f_tab[travel_destination_x][travel_destination_y]){
        temp_time=-1;
        field * t[4]={&f_tab[activex][activey-1],&f_tab[activex][activey+1]}
        if(activey!=0){
            temp_x=activex;
            temp_y=activey-1
            temp = &f_tab[activex][activey-1];
            temp->travel_time=time_count(active,temp);  //up
            if(time_count(active, temp)<temp_time||temp_time==-1){
              travel_start_y=temp_y
            }

        }
        if( activey<=y)
            f_tab[activex][activey+1].travel_time=time_count(f_tab[activex][activey],f_tab[activex][activey+1]);  //down
        if(activex<=x)
            f_tab[activex+1][activey].travel_time=time_count(f_tab[activex][activey],f_tab[activex+1][activey]);  //right
        if(activex!=0)
            f_tab[activex][activey-1].travel_time=time_count(f_tab[activex][activey],f_tab[activex-1][activey]);  //left
    }
}

































void mapa::add_lift(int, int, int, int, int, int){
}
