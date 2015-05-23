#include <iostream>
using namespace std;

struct skrzyzowanie{
	int longest_route;
	int id;
	int *stoki;
	int rozmiar;
};
typedef struct skrzyzowanie skrzyzowanie;

void skrzyzowanie_init(skrzyzowanie *s, int i){
	s->longest_route=0;
	s->rozmiar=0;
	s->stoki=new int[s->rozmiar];
    s->id=i;
}

void Stok_Push(skrzyzowanie *s, int value){
	int *stoki2;
	s->rozmiar++;
	stoki2 = new int[s->rozmiar];
	for(int i=0;i<s->rozmiar-1;i++){
		stoki2[i]=s->stoki[i];
	}
	s->stoki = new int[s->rozmiar];
	for(int i=0;i<s->rozmiar-1;i++){
		s->stoki[i]=stoki2[i];
	}
	delete [] stoki2;
	s->stoki[s->rozmiar-1] = value;
}

void wypisz_stoki(skrzyzowanie s){
	for(int i=0;i<s.rozmiar;i++){
		cout<<s.stoki[i]<<endl;
	}
}

//updatuje skrzyzowanie bez danego noda
void update_crossing_without(skrzyzowanie * s, int counter, skrzyzowanie * tab_skrzyz, int without){
if(counter>s->longest_route||counter==0){
	//if(s->stoki[tab_skrzyz->id]!=without){
		s->longest_route=counter;
            for(int i=0;i<s->rozmiar;i++){
                if(s->stoki[i]!=without){
                    update_crossing_without(&tab_skrzyz[s->stoki[i]], counter+1, tab_skrzyz,without);
                }
            }
        }
}

void wypisz_longest_route(skrzyzowanie * s,int skrzyzowania){
	for(int i=0;i<skrzyzowania;i++){
		cout<<"longest "<<s[i].longest_route<<endl;
	}
}

void wypisz_roz(skrzyzowanie * s,int skrzyzowania){
cout<<"roz1 ";
	for(int i=0;i<skrzyzowania;i++){
		cout<<s[i].rozmiar<<endl;
	}
cout<<" roz2\n";
}

int longest_way(int skrzyzowania, int tab_from[], int tab_to[], skrzyzowanie tab_skrzyz[]){
	int pomoc=0;
	for(int i=0;i<skrzyzowania;i++){
		if(tab_from[i]<=1&&tab_to[i]>=1){
			if(tab_skrzyz[i].longest_route>pomoc){
				pomoc=tab_skrzyz[i].longest_route;//cout <<"*";
			}
		}
	}
	return pomoc;
}

void clear_routes(skrzyzowanie * tab_skrzyz,int skrzyzowania){ //czysci longest route
	for(int i=0;i<skrzyzowania;i++){
		tab_skrzyz[i].longest_route=0;
	}
}
//updatuje wszystkie skrzyzowanie bez danego noda
void update_all_without(skrzyzowanie * tab_skrzyz, int skrzyzowania, int tab_from[], int tab_to[],int without){
	clear_routes(tab_skrzyz,skrzyzowania);
	//cout << "long" << longest_way(skrzyzowania,tab_from,tab_to,tab_skrzyz);
    //cout<<"with"<<without;
	for(int i=0;i<tab_skrzyz[without].rozmiar;i++){
		int temp=tab_skrzyz[without].stoki[i];

		if(tab_from[temp]>=1&&tab_to[temp]==1){
			 update_crossing_without(&tab_skrzyz[temp],0,tab_skrzyz,without);
		}
		//cout<<" "<<temp<<" "<<tab_from[temp]<<tab_to[temp]<<endl;
	}

	for(int i=0;i<skrzyzowania;i++){
		if(tab_from[i]>=1&&tab_to[i]==0&&without!=i){
            //cout<<" i "<<i<<" ";
			update_crossing_without(&tab_skrzyz[i],0,tab_skrzyz,without);

		}
	}
}

int main(){

	int skrzyzowania,stoki;
	int from,to;

	cin>>skrzyzowania;
	cin>>stoki;

	skrzyzowanie * tab_skrzyz;
	skrzyzowanie *array;
	array=new skrzyzowanie[skrzyzowania];
	tab_skrzyz=array;

	int * tab_from;
	int * array1;
	array1=new int[skrzyzowania];
	tab_from=array1;

	int * tab_to;
	int * array2;
	array2=new int[skrzyzowania];
	tab_to=array2;

	for(int i=0;i<skrzyzowania;i++){
		tab_from[i]=0;
		tab_to[i]=0;
	}


	for(int i=0;i<skrzyzowania;i++){
		skrzyzowanie_init(&tab_skrzyz[i],i);

	}

	for(int i=0;i<stoki;i++){
		cin>>from;
		cin>>to;

		tab_from[from]++;
		tab_to[to]++;

		Stok_Push(&tab_skrzyz[from],to);
	}

	int pom=-1;  //pom szuka "najkrótszej najdłuższej"
	int indeks;
	for(int i=0;i<skrzyzowania;i++){
		update_all_without(tab_skrzyz,skrzyzowania,tab_from,tab_to,i);
		int lw=longest_way(skrzyzowania,tab_from,tab_to,tab_skrzyz);  // lw -najdłuższa droga bez danego node'a
		//wypisz_longest_route(tab_skrzyz,skrzyzowania);
		//cout<<i<<lw<<endl;
		if(lw<pom||pom==-1){
            pom=lw;
			indeks=i;
		}
	}
	cout<<indeks<<" "<<pom;
	//wypisz_longest_route(tab_skrzyz,skrzyzowania);
}
