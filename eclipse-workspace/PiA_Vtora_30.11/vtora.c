/*
 * vtora.c
 *
 *  Created on: Nov 30, 2021
 *      Author: David
 */
#include<stdio.h>

int main(){
	int a[100],b[100];
	int i,j,n;
	float srvr=0;
	printf("Vnesete broj na elementi\n");
	fflush(stdout);

	scanf("%d",&n);
	printf("Vnesuvajte gi elementite na vektorot\n");
	fflush(stdout);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		srvr+=a[i];
	}
	j=0;
	srvr/=n;
	for(i=0;i<n;i++){
		if(a[i]>srvr){
			b[j] = a[i];
			j++;
		}
	}
	printf("Izleznata niza e: \n");

	for(i=0;i<j;i++){
		printf(" %d ",b[j]);
		fflush(stdout);
	}

	return 0;
}

