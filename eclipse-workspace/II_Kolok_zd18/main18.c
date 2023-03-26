/*
 * main18.c
 *
 *  Created on: Jan 18, 2022
 *      Author: David
 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void funkcija(char *niza,int *n){
	int i,j;
	int elniza=*n;
	for(i=0;i<elniza;i++){
		if(isdigit(*(niza+i))){
			for(j=i;j<elniza-1;j++){
				*(niza+j)=*(niza+j+1);
			}
			elniza--;
			i--;
	}
	*n=elniza;
}



int main(){
	char niza[100]="D2avid4 A45rsovski";
	int n;
	printf("%s\n",niza);
	fflush(stdout);
	funkcija(niza,&n);
	printf("%s",niza);
	fflush(stdout);
	return 0;

}

