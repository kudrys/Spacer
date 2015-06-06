#include "heap.h"
#include <iostream>
using namespace std;

heap::heap(){
    //empty
}

int heap::get_time(int i){
	//cout << x << y << endl;
	return map_tab[gety(i)][getx(i)].travel_time;
}

void heap::sort(){
//cout << "heap" << heap_size/2-2 << tab[0] << tab[1];

    cout << "sortujemy\n" << heap_size;
	for(int i=(heap_size/2)-1;i>=0;--i){
        int l=i*2+1;
        int r=l+1;

        draw();
        cout << "\ni: " << i;
        cout << "l: " << l << "r: " << r << endl;

		int temp=get_time(tab[i]);
		if (l<heap_size&&get_time(tab[l])<temp){
			int swap=tab[i];
			tab[i]=tab[l];
			tab[l]=swap;
		}
		if (r<heap_size&&get_time(tab[r])<temp){
			int swap=tab[i];
			tab[i]=tab[r];
			tab[r]=swap;
		}
	}
}

/**
*   Removes first element from heap and inserts last element in the place
*
*   @return - first element's travel time
*/
int heap::remove_first(){
    int temp=tab[0];
	tab[0]=tab[--heap_size];
	return temp;
}

void heap::add(int x, int y){
    tab[heap_size]=x*width+y;
    heap_size++;
}

int heap::getx(int i){
    return tab[i]/width;
}

int heap::gety(int i){
    return tab[i]%width;
}

void heap::draw(){
    cout <<endl;
    for(int i=0;i<heap_size;i++){
        cout << tab[i] << " ";
    }
}
