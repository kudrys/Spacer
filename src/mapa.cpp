#include "mapa.h"
#include "field.h"
#include <iostream>
using namespace std;

mapa::mapa(int x, int y){

    f_tab = new field* [y];
    for (int i = 0; i < y; i++) {
        f_tab[i] = new field [x];
    }
}

mapa::~mapa(){
    //dtor
}

void mapa::load_map() {


}







