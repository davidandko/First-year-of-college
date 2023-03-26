/*
 * pomalodX_main.c
 *
 *  Created on: Nov 10, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){

	int x,i=0,brbr=0;

	printf("Vnesi broj: ");
	fflush(stdout);
	scanf("%d",&x);
	printf("Vnesete broj: \n");
	fflush(stdout);

	while(i<=x){
		scanf("%d",&i);
		brbr++;
	}
	printf("Vnesovte %d broevi pomali ili ednakvi na %d",brbr-1,x);
	return 0;
}

