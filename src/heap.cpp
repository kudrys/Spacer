#include "heap.h"
#include <iostream>
using namespace std;

heap::heap(){
    //empty
}

/**
*   takes hashed number as an argument
*   @i -
*
*
*/
int heap::get_time(int i){
	return map_tab[gety(i)][getx(i)].travel_time;//check TODO
}

void heap::sort(){
	for(int i=heap_size/2;i>=0;--i){
        int l=i*2+1;
        int r=l+1;

		int temp=get_time(i);
		if(r<heap_size){
            if (get_time(l)<temp||get_time(r)<temp){
                if(get_time(l)<get_time(r))
                    swap(i,l);
                else
                    swap(i,r);
            }
		}else{
            if (l<heap_size&&get_time(l)<temp)
                swap(i,l);
		}/*
		int * node=NULL;
		if (l<heap_size&&get_time(l)<temp){
			node = &l;
		}
		if (r<heap_size&&get_time(r)<temp){
			node=&r;
		}
		if(node) swap(*node, i);
        */
	}
}

void heap::rebuild(){




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
    if(heap_size==tabsize)
        enlarge();
    tab[heap_size]=y*width+x;
    heap_size++;
}

void heap::enlarge(){
    int *tab2 = new int[tabsize*2];
    for(int i=0; i<tabsize; i++)
        tab2[i]=tab[i];
    int * temp=tab;
    tab=tab2;
    delete temp;
    tabsize*=2;
}

int heap::getx(int i){
    return tab[i]%width;
}

int heap::gety(int i){
    return tab[i]/width;
}

void heap::draw(){
    cout <<endl;
    for(int i=0;i<heap_size;i++){
        cout << tab[i] << " ";
    }cout << "\nt: ";
    for(int i=0;i<heap_size;i++){
        cout << get_time(i) << " ";
    }
}

void heap::swap(int a, int b){
	int swap=tab[a];
	tab[a]=tab[b];
	tab[b]=swap;
}

//metoda na odstrzal - albo nie
void heap::draw_times(int a, int b){
   for(int i=0;i<y;i++){
        cout<<"\n";
        for(int j=0;j<x;j++){
            if(a==j&&b==i)cout << '*';
            else cout << " ";
            if(map_tab[i][j].marked) cout << "#";
            else cout << " ";
            cout<<map_tab[i][j].travel_time;//<<" ";
            if(map_tab[i][j].travel_time<10)
                cout<<" ";
            if(map_tab[i][j].travel_time<100)
                cout<<" ";
        }
    }cout<<"\n\n";
}

void heap::draw_top(){
    int top = 7>heap_size?heap_size:7;
    cout << "\n\n";
    for(int i=0; i<top;i++){
        if (i==1||i==3)cout << "\n";
        cout << tab[i]<< "(" << get_time(i) << ") ";
    }

}
