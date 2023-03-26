/*
 * main13.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char funkcija(char c){


}


int main(int argc,char **argv){
char niza[100];
char c;
int i;
FILE *vlezna,*izlezna;
int i,dol;
if(argc!=3){
printf("Pogresen broj na argumenti vo dokumentot %s",argv[0]);
}
vlezna = fopen(argv[1],"r");
if(vlezna == NULL){
	printf("Vleznata datoteka ne se otvora");
}
izlezna = fopen(argv[2],"w");
if(vlezna == NULL){
	printf("Vleznata datoteka ne se otvora");
}

while((c=getc(vlezna)) != EOF){
	if(c != '\n'){
		niza[dol]=c;
		dol++;
}else{
	niza[dol]='\0';
	fprintf(izlezna,"%s",niza);
	for(i=0;i<dol;i++){
		switch (c){
			case '0': return 'nula-';
			case '1': return 'eden-';
			case '2': return 'dva-';
			case '3': return	'tri-';
			case '4': return 'cetiri';
			case '5': return 'pet-';
			case '6': return 'sest-';
			case '7': return 'sedum-';
			case '8': return	'osum-';
			case '9': return 'pet-';
		}
	}
	fprintf(vlezna,"\n");
	dol=0;
}
if(dol!=0){
	niza[dol]='\0';
	fprintf(izlezna,"%s",niza);
}

return 0;
}


