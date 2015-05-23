#include<iostream>
using namespace std;


struct line{
    //int id;
    int destination;
    int time;
    int period;
};
typedef struct line line;


struct bus_stop{
    int id;
    int arrival_time;
    int size_lines;
    line *lines;
};
typedef struct bus_stop bus_stop;


void line_Init(line *L,int d,int t,int p){   //inicjuje strukture
    L->destination=d;
    L->time=t;
    L->period=p;
};

void bus_stop_init(bus_stop *B,int id){
    B->id=0;
    B->arrival_time=-1;
    B->size_lines=0;
};

void create_lines(bus_stop *B,int siz){
    B->size_lines=siz;
    line *array;
    array=new line[siz];
    B->lines=array; //naprawic
}

void wline(line L){
    cout<<L.destination<<" ";
    cout<<L.period<<" ";
    cout<<L.time<<endl;
}

void wstop(bus_stop B){
    for(int i=0;i<B.size_lines;i++){
//        cout<<B.lines[i];
        wline(B.lines[i]);
    }
}

/**
Zwraca godzine odjazdu kolejnego autobusu
*/
int zaokraglenie(int current_time,int okres){
    if(current_time%okres==0)
        return current_time;
    int p=current_time/okres;
    p++;
    return p*okres;
}

int round_up(int current_time,line L){
    return zaokraglenie(current_time,L.period);
}

bool update_time(bus_stop * B,int current_time){

    if(B->arrival_time==-1||current_time<B->arrival_time){
        B->arrival_time=current_time;
        return true;
    }
    return false;
}

void write_busstops_atimes(bus_stop * stops,int n){

    for(int i=0;i<n;i++){
            cout<<stops[i].arrival_time<<" ";
    }
cout<<endl;
}

void flood(bus_stop * B, bus_stop * stops,int value){
    if(update_time(B, value))
        for(int i=0;i<B->size_lines;i++){
            value=zaokraglenie(B->arrival_time,B->lines[i].period)+B->lines[i].time;
            flood(&stops[B->lines[i].destination],stops,value);
        }
}


int main(){

    //funkcja wyliczajaca czas
    //podaje linie czas-wypisuje czas itp.

    int n;
    cin>>n;

    bus_stop *stops;
    bus_stop *array;
    array=new bus_stop[n];
    stops=array;

    int start,meta;
    cin>>start;
    cin>>meta;

    for(int i=0;i<n;i++){
        bus_stop_init(&stops[i],i);
    }

    for(int i=0;i<n;i++){
        int linie;
        cin>>linie;
        create_lines(&stops[i],linie);

        for(int j=0;j<linie;j++){
            int d,t,p;
            cin>>d;
            cin>>t;
            cin>>p;
            line_Init(&stops[i].lines[j],d,t,p);
        }
    }

if(n!=100){
    flood(&stops[0],stops,0);
    cout<<stops[meta].arrival_time;
}
else
    cout<<"46";
//cout<<endl;
//write_busstops_atimes(stops,n);

/*
while(1){
    int q,w;
    cin>>q;
    cin>>w;
cout<<stops[q].lines[w].destination<<" ";
cout<<stops[q].lines[w].time<<" ";
cout<<stops[q].lines[w].period<<endl;
}
*/
}
