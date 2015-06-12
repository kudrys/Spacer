#include "heap.h"
#include <iostream>
using namespace std;

heap::heap(){
    //empty
}
/**
*   takes heap index as an argument
*   @i - time of the field in map with coordinates (x, y) computed from the heap element
*
*/
int heap::get_time(int i){
    int r= map_tab[gety(i)][getx(i)].travel_time;//check TODO
    //cout << "i: " << i<< " y: " << gety(i) << " x " << getx(i) << "gettime: " << r << " :)\n";
	return r;//map_tab[gety(i)][getx(i)].travel_time;//check TODO
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



void heap::add(int x,int y){

    if(heap_size==tabsize)
        enlarge();

    //tab[heap_size]=y*width+x;
    //cout<<"\nadded x:"<<x<< "added y:"<<y<<endl;
    int value=y*width+x;
    int inserted = heap_size++;
    //int inserted = heap_size-1;

    int parent = (inserted-1)/2;
    //int value = get_time(inserted);
    cout <<"k"<< value <<"kek\n";
    tab[inserted]=value;
    while(inserted&&get_time(parent)>get_time(inserted)){
        //cout << "\nparent: " << get_time(parent) << " vslur: " << get_time(value);
        cout << "\nparent: " << parent << " vslur: " << value << " inserted " << inserted;
        swap(parent, inserted);//mozna przyspieszyc bez swapa
        inserted=parent;
        parent=(inserted-1)/2;
    }
    cout << "kekend\n";
    tab[inserted]=value;
    //draw_top();
    cout<<endl;
}


/**
*   Removes first element from heap and inserts last element in the place
*
*   @return - first element's travel time
*/
int heap::remove_first(){
cout << "before\n";
draw_top();
        if(heap_size--){
            int temp=tab[0];

            int value=get_time(heap_size);
            int index =tab[heap_size];
            cout<<"\nvalue"<<value;
            int inserted = 0;
            int child=1;

            while(child<heap_size){
                if(child+1<heap_size&&get_time(child+1)<get_time(child))
                    child++;
                if(value<=get_time(child))
                    break;
                //swap(child, inserted);
                tab[inserted]=tab[child];
                inserted= child;
                child=2*child+1;
            }tab[inserted]=index;
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
            cout << "after: \n";
            draw_top();
            return temp;                     //zle liczy bo 10<20. A ma wybrac 20. Get_time?

        }
    cout << "EXCEPTION ERROR MUAHAHAHAHAHA\nMUAHAHAHAHAHAHA\nMUAHAHAHHAHA\n";
    return 0;
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

/**
*   @i - index in heap
*   @return - y index of the map_tap or f_tab
*/
int heap::gety(int i){
    return tab[i]/width;
}

/**
*   @i - index in heap
*   @return - x index of the map_tab or f_tab
*
*/
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
        if (i==1||i==3||i==7)cout << "\n";
        cout << tab[i]<< "(" << get_time(i) << ") ";
    }

}
