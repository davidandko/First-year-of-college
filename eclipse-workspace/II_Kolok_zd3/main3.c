/*
 * main3.c
 *
 *  Created on: Jan 5, 2022
 *      Author: David
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,char **argv){
	FILE *vlezna,*izlezna;
	char c,a[100],brBuk=0;
	int zbir,i=0;
	if(argc != 3){
		printf("Pogresno koristenje- primam samo 2 datoteki\n");
	}
	vlezna = fopen(argv[1],"r");
	if(vlezna == NULL){
		printf("Ne mozam da otvoram vlezna datoteka\n");
	}
	izlezna = fopen(argv[2],"w");
	if(izlezna == NULL){
		printf("Ne mozam da otvoram izlezna datoteka\n");
	}
	while((c=fgetc(vlezna)) != EOF){
		if(c != '\n'){
			while(c != ' '){
			a[i] = c;
			brBuk++;
			i++;
			}
			for(i=0;i<brBuk;i++){
					printf("%c",a[i]);
				}
			if(isdigit(c)){
				zbir+=c;

			}
			if((zbir/3)<10){
				for(i=0;i<brBuk;i++){
					fprintf(izlezna,"%c",a[i]);
				}
				fprintf(izlezna," %d\n",zbir/3);
			}

}
		else{
				brBuk=0;
				a[0]='\0';
				zbir=0;
				i=0;
		}
	}
	printf("Zbirot: %d",zbir);
	return 0;
}

