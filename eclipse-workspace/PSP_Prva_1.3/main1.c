/*
 * main1.c
 *
 *  Created on: Mar 1, 2022
 *      Author: David
 */
#include<stdio.h>
#include<string.h>

enum boi {bela,crvena,zolta,zelena,sina,violetova,crna};
char *boite[] = {"bela","crvena","zolta","zelena","sina","violetova","crna"};
int main(){
	char vnesenaBoja[20];
	enum boi odbrana;
	int i;

	printf("Vnesete boja: \n");
	fflush(stdout);

	gets(vnesenaBoja);

	for(i=bela;i<=crna;i++){
		if(strcmp(vnesenaBoja,boite[i])==0){
		odbrana = i;
		}
	}

	switch(odbrana){
	case bela: printf("Belata boja e omilena na Kristijan Miloseski\n"); break;
	case crvena: printf("%s e omilena boja na Minea Hasik\n",boite[odbrana]);break;
	case zolta: printf("Zoltata e omilena boja na Ognen Sekuloski\n");break;
	case zelena: printf("%sta e omilena boja na Davor Stefanovski\n",boite[zelena]);break;
	case sina: printf("Sinata e omilena boja na Damjan Sokolovski\n");break;
	case violetova: printf("Violetovata e omilena boja na Viktorija Terzieva\n");break;
	case crna: printf("Crnata e omilena boja na David Arsovski\n");break;
	default: printf("%s boja ne mu e omilena nikomu!\n",vnesenaBoja);break;
	}
	return 0;
}



