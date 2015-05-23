#include<iostream>
using namespace std;

/**
Zwraca godzine odjazdu kolejnego autobusu
*/
int zaokraglenie2(int czas,int okres){
    if(czas%okres==0)
        return czas;
    int p=czas/okres;
    p++;
    return p*okres;
}

/**
czas calkowity
*/
int przyjazd(int czas,int okres,int czas_przejazdu){
    return zaokraglenie2(czas,okres)+czas_przejazdu;
}

//void nadaj_wartosc_tab(int[] tab2, int i, int[] temp){





//}

int mainhdfhdfg(){

    int n,start,meta;
    cin>>n;
    cin>>start;
    cin>>meta;
    int tab[n][1000][3];           //dane wprowadzane
    int tab2[n];                 //liczba odjazdow z poszczegolnych przystankow
    int licznik=1;               //zlicza mozliwe drogi

    for(int i=0;i<n;i++){
        int linie;
        cin>>linie;

        //tab[i][linie][0]=0;
        tab2[i]=linie;
        //licznik=tab2[i]*tab2[i+1];
        if(linie!=0)
        licznik*=linie;

        for(int j=0;j<linie;j++){
            int t,d,s;
            cin>>t;
            tab[i][j][0]=t;         //wczytywanie przystanek docelowy
            cin>>d;
            tab[i][j][1]=d;         //wczytywanie czas jazdy do p.dolelowego
            cin>>s;
            tab[i][j][2]=s;         //wczytywanie okresu autobusu


        }
    }

//--------------------------- algorytm ----------------------------------//
    int minitime=-1;

    for(int i=0;i<licznik;i++){
        int temp[n-1];
        int tempi=i;

    //nadaj_wartosc_tab(tab2,i,&temp);
        for(int j=0;j<n-1;j++){                    //translacja na wartosci tymczasowe.

            if(tab2[j]!=0){
            temp[j]=tempi%tab2[j];
            tempi/=tab2[j];
            }

        }

        int time=0;
        for(int j=start;j<meta;){ //i= nr przystanku

            time=przyjazd(time,tab[j][temp[j]][2],tab[j][temp[j]][1]);

            j=tab[j][temp[j]][0];

        }
        if(time<minitime||minitime==-1)
            minitime=time;
    //cout<<time;
    }
cout<<minitime;

}

