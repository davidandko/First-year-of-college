/*
 * main2.c
 *
 *  Created on: Dec 28, 2021
 *      Author: David
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main (int argc,char **argv){
	FILE *vlezna,*izlezna;
	int brred = 1, brRIs = 0;
	int brMal = 0;
	char c;
	if(argc != 3){
		printf("Losho povikuvanje\n");
		exit(-1);
	}
	vlezna = fopen(argv[1],"r");
	if(vlezna == NULL){
		printf("Prvata datoteka e losho otvorena\n");
		exit(-1);
	}
	izlezna = fopen(argv[2],"w");
	if(izlezna == NULL){
		printf("Vtorata datoteka e losho otvorena\n");
		exit(-1);
	}
	while((c = fgetc(vlezna)) != EOF){
		if(c == '\n'){
			if(brMal>10){
				fprintf(izlezna,"%d\n",brred);
				brRIs++;
			}
			brMal = 0;
			brred++;
		}
		else{
			if(islower(c)){
				brMal++;
			}
		}
	}
	if(brMal>10){
		fprintf(izlezna,"%d",brred);
		brRIs++;
	}
	if(brRIs == 1){
		fprintf(izlezna,"\nVo datotekata bese najden %d takov red\n",brRIs);
	}else{
	fprintf(izlezna,"\nVo datotekata bea najdeni %d takvi redovi\n",brRIs);
	}
	fclose(vlezna);
	fclose(izlezna);

	return 0;
}
