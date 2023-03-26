/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int poz,min,broj,k=1;
	printf("Za kraj vnesi znak");
	fflush(stdout);
	scanf("%d",&broj);
	poz=1;
	min=broj;
	while(scanf("%d",&broj)){
		k++;
		if(broj<min){
			min=broj;
			poz=k;
		}

	}



	printf("Minimumot na nizata e %d a pozicijata e %d",min,poz);

return 0;
}
