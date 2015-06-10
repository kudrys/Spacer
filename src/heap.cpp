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
		int * nodent * node=NULL;
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



void heap::add(int v){
 /*
    if(heap_size==tabsize)
        enlarge();

    //tab[heap_size]=y*width+x;
    cout<<"\nadded x:"<<x<< "added y:"<<y<<endl;
    tab[heap_size]=y*width+x;
    heap_size++;
    int inserted = heap_size-1;

    int parent = (inserted)/2;
    int value = get_time(inserted);
    while(heap_size&&get_time(parent)<value){
        swap(parent, inserted);//mozna przyspieszyc bez swapa
        inserted=parent;
        parent=(inserted-1)/2;
    }
    //draw_top();
     */
    //int value=y*width+x;

    cout<<"\nv="<<v;
    int inserted = heap_size++;//heap_size-1;

    int parent = (inserted-1)/2;

    //int value = tab[heap_size-1];
    while(inserted>0 && tab[parent]>v){
        //swap(inserted , parent);//mozna przyspieszyc bez swapa
        tab[inserted]=tab[parent];
        inserted=parent;
        parent=(inserted-1)/2;
    }tab[inserted]=v;

    //cout<<heap_size<<endl;
    //tab[inserted]=value;
    //draw();
    cout<<endl;
}


/**
*   Removes first element from heap and inserts last element in the place
*
*   @return - first element's travel time
*/
int heap::remove_first(){
        if(heap_size--){
            int v=tab[heap_size];

            int inserted = 0;
            int child=1;

            int temp=tab[0];
            while(child<heap_size){
                if(child+1<heap_size&&get_time(child+1)<get_time(child))
                    child++;
                if(v<=get_time(child))
                    break;
                //swap(child, inserted);
                tab[inserted]=tab[child];
                inserted= child;
                child=child*2+1;
            }
            /*
            tab[inserted]=v;
            if(heap_size--){
                int temp=tab[0];
                //tab[0]=tab[--heap_size];
                //heap_size--;
                int value = tab[heap_size];
                int inserted = 0;
                int child = 1;

                while(child<heap_size){
                    if(child+1 > heap_size&&tab[child+1] < tab[child])
                        child++;
                    if(value <= tab[child])
                        break;
                    swap(inserted , child);
                    //tab[inserted]=tab[child];
                        inserted = child;
                        child=2*child+1;
                    }tab[inserted]=value;
                //tab[inserted]=value;
                //draw_top();
            */
            cout<<"\ntemp:"<<temp<<endl;
            return temp;                     //zle liczy bo 10<20. A ma wybrac 20. Get_time?

        }
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
        //cout << tab[i] << " ";
    }//cout << "\nt: ";
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
    int top = 25>heap_size?heap_size:25;
    cout << "\n\n";
    for(int i=0; i<top;i++){
        if (i==1||i==3)cout << "\n";
        cout << tab[i]<< "(" << get_time(i) << ") ";
    }

}
