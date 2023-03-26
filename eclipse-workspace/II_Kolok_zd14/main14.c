/*
 * main14.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
//termin 1 grupa eden zadaca 3
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char **argv){

	FILE *vlezna,*izlezna;

	if(argc != 3){
		printf("Error! File %s",argv[0]);
		exit(-1);
	}

	vlezna=fopen(argv[1],"r");
	if(vlezna == NULL){
		printf("File %s cant open",argv[1]);
		exit (-1);
	}
	izlezna=fopen(argv[2],"w");
	if(izlezna==NULL){
		printf("File %s cant open",argv[2]);
		exit(-1);
	}
	int s1,s2,s3;
	float prosek;
	char server[100];
	while(fscanf(vlezna,"%s %d %d %d",server,&s1,&s2,&s3) == 4){
		prosek=(float)(s1+s2+s3)/3.0;
		if(prosek<10){
			fprintf(izlezna,"%s %.2f",server,prosek);
		}
	}


	fclose(vlezna);
	fclose(izlezna);
	return 0;
}

