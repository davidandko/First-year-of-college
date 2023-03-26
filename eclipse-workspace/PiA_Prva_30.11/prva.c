/*
 * prva.c
 *
 *  Created on: Nov 30, 2021
 *      Author: David
 */
#include<stdio.h>

int main(){
	int a[20];
	int i,n;
	float srvr=0;


	printf("Vnesete dolzina na vektorot\n");
	fflush(stdout);
	scanf("%d",&n);

	printf("Vnesuvajte gi elementite na vektorot\n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);

	}
	for(i=0;i<n;i++){
		srvr=srvr+a[i];
	}
	srvr=srvr/n;

	printf("Srednata vrednost e %.2f",srvr);

	return 0;
}

