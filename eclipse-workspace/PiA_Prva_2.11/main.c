/*
 * main.c
 *
 *  Created on: Nov 2, 2021
 *      Author: David
 */
#include<stdio.h>
int main(){
int broj1, broj2, rezultat = 0;
char znak;
printf("Vnesete operator i dva broja: ");
fflush(stdout);
scanf("%c%d%d",&znak, &broj1, &broj2);

	switch(znak){
	case '+': rezultat = broj1+broj2; break;

	case '-': rezultat = broj1-broj2; break;

	case '*': rezultat = broj1*broj2; break;

	case '/':  if(broj2 !=0){
		rezultat=broj1/broj2;
	}
	break;

	case '%': rezultat = broj1%broj2; break;

	default: printf("Vnesenata operacija e nepoznata\n");
	}
	printf("Rezultatot e: %d \n",rezultat);

	return 0;
}

