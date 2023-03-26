/*
 * main3.c
 *
 *  Created on: Mar 1, 2022
 *      Author: David
 */
#include<stdio.h>

enum pozicii {levokr,levbeg,centr,piker,desebeg,desnokr,golman};
char *poziciite[] = {"Levo krilo","Lev beg","Centralen beg","Piker","Desen Beg","Desno krilo","Golman"};
typedef struct igrac{
	char ime[30];
	enum pozicii pozicija;
	int brGol;
}igrach;
typedef struct reprezent{
	char ime[30];
	igrach igraci[10];
	int vkGolovi;
	int brIgr;
}reprezentacija;
void pechatiIgr(igrach I){
	printf("%s pozicija: %d, broj golovi: %d\n",I.ime,I.pozicija,I.brGol);
}

void presmetajVKGolovi(reprezentacija *reprezentacii,int brRep){
	int i,j;
	for(i=0;i<brRep;i++){
		reprezentacii[i].vkGolovi = 0;
		for(j=0;j<reprezentacii[i].brIgr;j++){
			reprezentacii[i].vkGolovi += reprezentacii[i].igraci[j].brGol;
		}
	}
}
void najdiNajdobarSostav(reprezentacija *reprezentacii,int brRep){
	igrach najdobri[7];
	int i,j;
	for(i=0;i<7;i++){
		najdobri[i].brGol = -1;
	}
	for(i=0;i<brRep;i++){
		for(j=0;j<reprezentacii[i].brIgr;j++){
			switch(reprezentacii[i].igraci[j].pozicija){
			case levokr:
				if(najdobri[levokr].brGol < reprezentacii[i].igraci[j].brGol){
				najdobri[levokr]=reprezentacii[i].igraci[j];
			}break;
			case levbeg:
				if(najdobri[levbeg].brGol<reprezentacii[i].igraci[j].brGol){
					najdobri[levbeg] = reprezentacii[i].igraci[j];
				}break;
			case centr:
				if(najdobri[centr].brGol < reprezentacii[i].igraci[j].brGol){
					najdobri[centr]=reprezentacii[i].igraci[j];
				}break;
			case piker:
				if(najdobri[piker].brGol<reprezentacii[i].igraci[j].brGol){
					najdobri[piker] = reprezentacii[i].igraci[j];
				}break;
			case desebeg:
				if(najdobri[desebeg].brGol<reprezentacii[i].igraci[j].brGol){
					najdobri[desebeg] = reprezentacii[i].igraci[j];
				}break;
			case desnokr:
				if(najdobri[desnokr].brGol<reprezentacii[i].igraci[j].brGol){
					najdobri[desnokr] = reprezentacii[i].igraci[j];
				}break;
			case golman:
				if(najdobri[golman].brGol<reprezentacii[i].igraci[j].brGol){
					najdobri[golman] = reprezentacii[i].igraci[j];
				}break;
			}


		}
	}
	for(i=levokr;i<golman;i++){
		pechatiIgr(najdobri[i]);
	}

}
int main(){
	//imam greska vo zagradite tuka, drugoto e  tocno
	reprezentacija R[2]={{"Makedonija",{{"Manaskov",levokr,17},{"Filip",levbeg,18},{"Igor",centr,6},{"Stoilov",piker,25},{"Kire",desebeg,9},
			{"Georgievski",desnokr,12},{"Mitrevski",golman,1},0,7}},
			{"AA",{{"A1",levokr,1},{"A2",levbeg,2},{"A3",centr,3},{"A4",piker,4},{"A5",desebeg,5},{"A6",desnokr,7},{"A7",golman,8}}},0,7}
	};
najdiNajdobarSostav(R,2);
return 0;
}
