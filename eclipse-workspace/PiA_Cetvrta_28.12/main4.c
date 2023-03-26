/*
 * main4.c
 *
 *  Created on: Dec 28, 2021
 *      Author: David
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 81
int main(int argc, char **argv){
	FILE *vlezna;
	char nizaRed[MAX],c;
	int brZ,iw,brR = 0,i,dol;

	if(argc != 2){
		printf("pogreshno povikuvanje\n");
		exit(-1);
	}
	vlezna = fopen(argv[1],"r");
	if(vlezna == NULL){
		printf("Losho otvorena datoteka\n");
		exit(-1);
	}
	while(fgets(nizaRed,80,vlezna) != NULL){
		dol = strlen(nizaRed);
		brZ=0;
		iw=0;
		//bitno
		//so fgets bukva po bukva
		for(i=0;i<dol;i++){
			c = nizaRed[i];
			if(isalpha(c)){
				if(iw==0){
					iw = 1;
					brZ++;
				}
			}else{
				if(iw == 1){
					iw = 0;
				}
			}
		}
		//bitno
		if(brZ>10){
				brR++;
			}
	}

	fclose(vlezna);
	printf("Brojot na redovi koj go ispolnuvaat uslovot e %d\n",brR);

	return 0;
}
