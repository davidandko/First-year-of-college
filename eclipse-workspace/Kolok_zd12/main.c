/*
 * main.c
 *
 *  Created on: Nov 19, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int max,min,broj;

	printf("Vnesuvaj broevi, za da prekines vnesi znak \n");

	fflush(stdout);
	 scanf("%d",&broj);
	 min=broj; max=broj;
	 while(scanf("%d",&broj)){
		 if(broj<min){
			 min=broj;
		 }
		 if(broj>max){
			 max=broj;
		 }
	 }
	printf("Max: %d ; Min: %d",max,min);
	return 0;
}

