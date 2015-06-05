#include "heap.h"

heap::heap(mapa * m){
	this->m=m;
	width=m->x;
	tabsize=100;
	heap_size=0;
	tab = new int [tabsize];
    //ctor
}

int heap::get_time(int i){
	int temp = tab[i];
	int x=temp/width;
	int y=temp%width;
	//cout << x << y << endl;
	return m->f_tab[x][y].travel_time;
}

void heap::sort(){
	for(int i=heap_size/2-2;i<0;--i){
		int temp=get_time(tab[i]);
		if (get_time(tab[i*2+1])<temp){
			int swap=tab[i];
			tab[i]=tab[i*2+1];
			tab[i*2+1]=swap;
		}
		if (get_time(tab[i*2+2])<temp){
			int swap=tab[i];
			tab[i]=tab[i*2+2];
			tab[i*2+2]=swap;
		}
	}
}

void remove_first(){
	tab[0]=tab[--heapsize];
}
