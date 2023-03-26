/*
 * main3.c
 *
 *  Created on: Jan 11, 2022
 *      Author: David
 */
#include<stdio.h>
#include<ctype.h>

int main(int argc,char **argv){
	FILE *vlezna;
	FILE *izlezna;
	char c;
	int iw=0,brZb=0,redB = 1,brRed = 0;
	if(argc != 3){
		printf("Pogresna upotreba na programata\n");
		return -1;
	}
	vlezna = fopen(argv[1],"r");
	if(vlezna == NULL){
		printf("Neuspeshno otvoranje na prvata datoteka\n");
		return -1;
	}
	izlezna = fopen(argv[2],"w");
	if(izlezna == NULL){
		printf("Neuspeshno otvoranje na vtorata datoteka\n");
		return -1;
	}
	while((c=fgetc(vlezna))!= EOF){
		if(c == '\n'){
			if(brZb>4){
				fprintf(izlezna,"Red %d\n",redB);
				brRed++;
			}
			redB++;
			brZb=0;
			iw=0;
		}else{
			if(isalpha(c)){
				if(iw == 0){
					brZb++;
				}
				iw=1;
			}else{
				iw=0;
			}
		}

	}
	if(brZb > 4){
		fprintf(izlezna,"Red %d\n",redB);
		brRed++;
	}
	fprintf(izlezna,"\nPostojat %d takvi reda.",brRed);
	fclose(vlezna);
	fclose(izlezna);
return 0;
}


