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


}





























void mapa::add_lift(int, int, int, int, int, int){
}






