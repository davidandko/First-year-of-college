/*
 * main1.c
 *
 *  Created on: Dec 28, 2021
 *      Author: David
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int main(int argc, char **argv){
	FILE *vlezna,*izlezna;
	char niza[20],c;
	int i,dol = 0;

	if(argc != 3){
		printf("Programata se povikuva so iminja na 2 datoteki\n");
		exit(-1);
	}

	vlezna = fopen(argv[1],"r");
	if(vlezna == NULL){
		printf("Problem so vleznata datoteka\n");
		exit(-1);
	}
	izlezna = fopen(argv[2],"w");
	if(izlezna == NULL){
		printf("Vtorata datoteka ne e pravilno otvorena\n");
	}
	while((c = fgetc(vlezna)) != EOF){
		if(c != '\n'){
			niza[dol] = c;
			dol++;
		}
		else{
			niza[dol] = '\0';
			// pecatenje vo izlezna datoteka
			fprintf(izlezna,"%s",niza);
			for(i=0;i<dol;i++){
				switch(niza[i]){
				case '0': fprintf(izlezna,"-nula"); break;
				case '1': fprintf(izlezna,"-eden"); break;
				case '2': fprintf(izlezna,"-dva"); break;
				case '3': fprintf(izlezna,"-tri"); break;
				case '4': fprintf(izlezna,"-cetiri"); break;
				case '5': fprintf(izlezna,"-pet"); break;
				case '6': fprintf(izlezna,"-sest"); break;
				case '7': fprintf(izlezna,"-sedum"); break;
				case '8': fprintf(izlezna,"-osum"); break;
				case '9': fprintf(izlezna,"-devet"); break;
				}
			}
			fprintf(izlezna,"\n");
							dol = 0;
		}
	}
	if(dol != 0){
		niza[dol] = '\0';
		fprintf(izlezna,"%s",niza);
		for(i=0;i<dol;i++){
			switch(niza[i]){
			case '0': fprintf(izlezna,"-nula"); break;
			case '1': fprintf(izlezna,"-eden"); break;
			case '2': fprintf(izlezna,"-dva"); break;
			case '3': fprintf(izlezna,"-tri"); break;
			case '4': fprintf(izlezna,"-cetiri"); break;
			case '5': fprintf(izlezna,"-pet"); break;
			case '6': fprintf(izlezna,"-sest"); break;
			case '7': fprintf(izlezna,"-sedum"); break;
			case '8': fprintf(izlezna,"-osum"); break;
			case '9': fprintf(izlezna,"-devet"); break;
			}
		}
	}
	fclose(vlezna);
	fclose(izlezna);
	return 0;
}

