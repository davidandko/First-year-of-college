/*
 * main.c
 *
 *  Created on: Nov 1, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int poc, kraj, i, pom, prev, cifra;
	printf("Vnesete granici na intervalot\n");
	fflush(stdout);
	scanf("%d%d",&poc,&kraj);
	for(i=poc; i<=kraj; i++){
		prev = 0;
		pom = i;

		while(pom>0){
			cifra = pom%10;
			pom = pom/10;

			prev = prev*10+cifra;

		}
		if(i==prev){
			printf("%d  ",i);
		}
	}


	return 0;
}

