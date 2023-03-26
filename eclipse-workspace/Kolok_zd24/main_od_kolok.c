/*
 * main_od_kolok.c
 *
 *  Created on: Nov 25, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
	int sumacifri=0,pom,cifra1,cifra2,cifra3,izlez=0,broj,brcifri=0;
	printf("Vnesete broj so paren broj na cifiri: \n");
	fflush(stdout);

	scanf("%d",&broj);
pom=broj;
	while(pom>0){

		brcifri++;
		pom/=10;
	}

	if(brcifri%2==0){
		while(broj>0){
			cifra1=broj%10;
			cifra2=(broj/10)%10;
			sumacifri+=(cifra2*10)+cifra1;
			broj/=100;
		}
		while(sumacifri>0){
				cifra3=sumacifri%10;
				izlez+=cifra3;
				sumacifri/=10;
			 }

			printf("Broj: %d",izlez);
	}
	else{
		printf("Vnesovte broj sto ima neparen broj na cifri\n");
	}


	return 0;
}

