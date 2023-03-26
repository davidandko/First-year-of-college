/*
 * main3.c
 *
 *  Created on: Dec 29, 2021
 *      Author: David
 */
#include<stdio.h>
#include <ctype.h>
#include<stdlib.h>
int main(int argc, char **argv){

	FILE *vlezna;
int i;
	for(i=1;i<=argc;i++){
		if((vlezna=fopen(argv[i],"r"))!= NULL){
			printf("Datotekata e otvorena za citanje.\n");
	}
		if((vlezna=fopen(argv[i],"r"))== NULL){
					printf("Datotekata ne se otvara za citanje.\n");
			}
		if((vlezna=fopen(argv[i],"w"))!= NULL){
			printf("Datotekata e otvorena za zapisuvanje.\n");
		}
		if((vlezna=fopen(argv[i],"w"))== NULL){
					printf("Datotekata ne se otvara za zapisuvanje.\n");
		if((vlezna=fopen(argv[i],"r"))== NULL && (vlezna=fopen(argv[i],"w"))== NULL){
			printf("Datotekata ne se otvara ni za zapisuvanje ni za citanje, zatvaram programa.\n");
			exit(-1);
		}
	}
		fclose(vlezna);
}

	return 0;

}
