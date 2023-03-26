/*
 * main.c
 *
 *  Created on: Nov 6, 2021
 *      Author: David
 */
#include<stdio.h>
int main (){
	int N,brojac,broj,p=0,s=0,n=0;
	printf("Kolku broevi sakate da vnesite? \n");
	fflush(stdout);
	scanf("%d ", &N );
	brojac=1;
	do{
		printf(" Vnesi broj : \n");
		fflush(stdout);
		scanf("%d", &broj );
	if ( broj > 0 ){
			p++;
			s+=broj;
	}
		else n++;

		brojac++;
	} while ( brojac <= N );

	printf("Srednata vrednost na pozitivnite broevi e: %f \n", (float)s/p );
	printf("Broj na negativni vneseni broevi: %d ", n);
		return 0;

	}

