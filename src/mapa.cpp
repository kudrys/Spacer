#include "mapa.h"
#include "field.h"
#include <iostream>
using namespace std;

mapa::mapa(){
    //ctor
}

mapa::~mapa(){
    //dtor
}

void mapa::create_map() {

    tab = new field* [y];
    for (int i = 0; i < y; i++) {
        tab[i] = new field [x];
    }
}


