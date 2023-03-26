/*
 * petta.c
 *
 *  Created on: Nov 30, 2021
 *      Author: David
 */
#include<stdio.h>

int main(){
	int a[5]={1,2,3,5,7}; // inicijalizacija na vektor direktno vo programa
	int i,n=5;
	int b[10];
//printf("Vnesete broj na elementi na nizata: \n");
	//fflush(stdout);
	for(i=0;i<n;i++){
		b[i] = a[i]+a[n-1-i];


	}

	for(i=0;i<n;i++){
		printf("%d",b[i]);
	}

	return 0;
}

