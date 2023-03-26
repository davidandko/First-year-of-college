/*
 * main17.c
 *
 *  Created on: Jan 17, 2022
 *      Author: David
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc,char **argv){
	FILE *vlezna;
	if(argc!=2){
		printf("Pogresno koristenje na programata %s\n",argv[1]);
		exit(-1);
	}
	vlezna=fopen(argv[1],"r");
	if(vlezna == NULL){
		printf("Vleznata datoteka %s ne se otvora\n",argv[2]);
		exit(-1);
	}
	char zbor[80],c,bukvi[21];
	int brBukvi=0,i,brzbor=0,isWord=0,dol=0;
	while((c=fgetc(vlezna)) == EOF){

		if(isalpha(c)){
			if(!isWord){
				bukvi[dol]=c;
				dol++;
				isWord=1;

			}
			if(isWord){
				isWord=0;
				bukvi[dol]='\0';
				brzbor++;
			}
		}
		for(i=0;i<dol-1;i++){
			brBukvi=0;
			for(int j=i+1;j<dol;j++){
				if(tolower(bukvi[i])==tolower(bukvi[j])){
					brBukvi++;
				}
			}
			if(brBukvi=>3){
			printf("Takov zbor %s",bukvi)
			}
		}

	}

	return 0;
}

