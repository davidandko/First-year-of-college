/*
 * main.c
 *
 *  Created on: Nov 17, 2021
 *      Author: David
 */
//6ta od zadaci od auditoriski za funkcii

#include<stdio.h>

int max(int n){
	int cifra,prethodenbr=0;

	while(n>0){
		cifra=n%10;
		if(prethodenbr<cifra){
			prethodenbr=cifra;
		}
		n/=10;

	}
	return prethodenbr;
}
int main(){

	int n;
	printf("Vnesi broj: \n");
	fflush(stdout);
	scanf("%d",&n);
	printf("Najgolema cifra na brojot %d e: %d",n,max(n));

	return 0;
}


