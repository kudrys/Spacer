#include "heap.h"
#include <iostream>
using namespace std;

heap::heap(){
    //empty
}

int heap::get_time(int i){
	//cout << x << y << endl;
	//cout << "xy: " << i << " " << tab[i] << " " << getx(i) << " " << gety(i)<< "\n";
	return map_tab[getx(i)][gety(i)].travel_time;//check TODO
}

void heap::sort(){
    //cout << "heap" << heap_size/2-2 << tab[0] << tab[1];

    cout << "sortujemy\n" << heap_size;
	for(int i=(heap_size/2)-0;i>=0;--i){
        int l=i*2+1;
        int r=l+1;
/*
        draw();
        cout << "\ni: " << i;
        cout << "l: " << l << "r: " << r << endl;
*/
		int temp=get_time(i);
		if (l<heap_size&&get_time(l)<temp){
			swap(i,l);
		}
            draw();
		if (r<heap_size&&get_time(r)<temp){
			swap(i,r);
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
    }cout << "\nt: ";
    for(int i=0;i<heap_size;i++){
        cout << get_time(tab[i]) << " ";
    }
}

void heap::swap(int a, int b){
	int swap=tab[a];
	tab[a]=tab[b];
	tab[b]=swap;
}

void heap::draw_times(int a, int b){
   for(int i=0;i<y;i++){
        cout<<"\n";
        for(int j=0;j<x;j++){
            if(map_tab[i][j].marked){

                if(a==j&&b==i){
                    cout<<"[] ";
                }else{
                    cout << "-- ";
                }
                continue;
            }else{
                cout<<map_tab[i][j].travel_time<<" ";
                if(map_tab[i][j].travel_time<10)
                    cout<<" ";
            }
        }

    }cout<<"\n\n";
}
